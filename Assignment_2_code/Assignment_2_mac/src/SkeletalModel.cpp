///=========================================================================================///
///
///                       Functions to be filled in for Assignment 2   
///
///           IMPORTANT: you ONLY need to work on functions with TODO in this section    
///    
///=========================================================================================///


#include "SkeletalModel.h"


///=========================================================================================///
///                                    Load .skel File    
///=========================================================================================///


// TODO: Load the skeleton from file here, create hierarchy of joints
//       (i.e., set values for m_rootJoint and m_joints)
void SkeletalModel::loadSkeleton( const char* filename )
{
    string path = "../data/";
    ifstream fileStream(path.append(filename), ios::in);

    if (!fileStream.is_open()) {
        cout << "Failed to read " << filename << "! File doesn't exist." << endl;
        return;
    }

    float x, y, z;
    int j;
    while (fileStream >> x >> y >> z >> j) {
        auto *joint = new Joint();
        joint->transform = translate(mat4(1.0f), vec3 (x, y, z));
        m_joints.push_back(joint);

        if (j == -1) {
            m_rootJoint = joint;
        } else {
            m_joints[j]->children.push_back(joint);
        }
    }

    fileStream.close();
}




///=========================================================================================///
///                         Compute transformations for Joints and Bones     
///=========================================================================================///

void SkeletalModel::computeTransforms()
{
    if( m_joints.size() == 0 )
        return;

    computeJointTransforms();

    computeBoneTransforms();
}

// Compute a transformation matrix for each joint (i.e., ball) of the skeleton
void SkeletalModel::computeJointTransforms( )
{
    jointMatList.clear();

    m_matrixStack.clear();

    computeJointTransforms(m_rootJoint, m_matrixStack);
}

// TODO: You will need to implement this recursive helper function to traverse the joint hierarchy for computing transformations of the joints
void SkeletalModel::computeJointTransforms(Joint* joint, MatrixStack matrixStack)
{
    matrixStack.push(transpose(joint->transform));
    for (auto & i : joint->children) {
        computeJointTransforms(i, matrixStack);
    }

    jointMatList.push_back(matrixStack.top());
    matrixStack.pop();
}


// Compute a transformation matrix for each bone (i.e., cylinder) between each pair of joints in the skeleton
void SkeletalModel::computeBoneTransforms( )
{
    boneMatList.clear();

    m_matrixStack.clear();

    computeBoneTransforms(m_rootJoint, m_matrixStack);
}

// TODO: You will need to implement this recursive helper function to traverse the joint hierarchy for computing transformations of the bones
void SkeletalModel::computeBoneTransforms(Joint* joint, MatrixStack matrixStack)
{
    matrixStack.push(transpose(joint->transform));

    for (auto & i : joint->children) {
        vec3 direction = i->transform[3];

        vec3 z_axis = normalize(direction);
        vec3 y_axis = normalize(cross(z_axis, vec3(0, 0, 1)));
        vec3 x_axis = normalize(cross(y_axis, z_axis));

        mat3 rotation(x_axis, y_axis, z_axis);
        mat4 T = translate(mat4(1.0f), vec3(0, 0, 0.5));
        mat4 S = scale(mat4(1.0f), vec3(0.01f, 0.01f, length(direction)));
        mat4 R = mat4(rotation);

        boneMatList.push_back(transpose(R * S * T) * matrixStack.top());

        computeBoneTransforms(i, matrixStack);
    }
    matrixStack.pop();
}




///=========================================================================================///
///                              Set Joint Angles for Transform     
///=========================================================================================///

// TODO: Set the rotation part of the joint's transformation matrix based on the passed in Euler angles.
void SkeletalModel::setJointTransform(int jointIndex, float angleX, float angleY, float angleZ)
{
    mat4 Mx, My, Mz;
    Mx = rotate(mat4(1.0f), angleX, vec3(0, 1, 1));
    My = rotate(mat4(1.0f), angleY, vec3(1, 0, 1));
    Mz = rotate(mat4(1.0f), angleZ, vec3(1, 1, 0));

    Joint* joint = m_joints[jointIndex]; // defining pointer variable
    m_joints[jointIndex]->transform = joint->transform * Mz * My * Mx; // applying rotations
}





