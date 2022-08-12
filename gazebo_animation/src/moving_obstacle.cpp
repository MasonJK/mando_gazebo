// #include <ros/ros.h>
// #include "gazebo_msgs/ModelState.h"
// #include "gazebo_msgs/ModelStates.h"
// #include "geometry_msgs/Twist.h"

// #include <iostream>
// #include <math.h>

// using namespace std;

// // Publisher
// ros::Publisher obstacle_publisher_;

// // Message
// gazebo_msgs::ModelState model_msg;
// geometry_msgs::Twist tw_msg;
// gazebo_msgs::ModelStates model;

// // ROS Time
// ros::Time last_time_;
// ros::Time current_time_;


// int main(int argc, char** argv)
// {
//     ros::init(argc, argv, "moving_obstacle");
//     ros::NodeHandle nh_;

//     ros::Rate rate(100); // Hz(Control Frequncy)

//     obstacle_publisher_ = nh_.advertise<gazebo_msgs::ModelState>("/gazebo/set_model_state", 100);

//     unsigned int cnt = 0;

//     const double controlPeriod = 0.2; // sec

//     while(ros::ok())
//     {
//         ROS_INFO("moving_obstacle node ...");

//         model = *(ros::topic::waitForMessage<gazebo_msgs::ModelStates>("/gazebo/model_states"));

//         current_time_ = ros::Time::now();
//         double dt = (current_time_ - last_time_).toSec();

//         static bool init_run = true;

//         if (init_run)
//         {
//             last_time_ = current_time_;
//             init_run = false;
//             continue;
//         }

//         if(!model.name.empty())
//         {
//             for(int i=0; i<model.name.size(); i++)
//             {
//                 // Find the obstacle name
//                 if(strcmp(model.name[i].data(), "obstacle") == 0)
//                 {
//                     // cout << "Find!" << endl;

//                     std::string model_name = "obstacle";


//                      double period = 1.0 / controlPeriod;
//                      double mag = 2.0;

//                    // Set the state
//                     model_msg.model_name = model_name;
//                     model_msg.pose = model.pose[i];
//                     // model_msg.pose.position.x = 1.0 * sin(2.0*M_PI/period * (double)cnt);

//                     cout << "time = " << dt << endl;

//                     // model_msg.twist.linear.x = 1.0 * sin(2.0*M_PI/period * (double)cnt);
//                     model_msg.twist.linear.x = 0.0;
//                     model_msg.twist.angular.z = 3.0 * sin(2.0*M_PI/period * (double)cnt);

//                     obstacle_publisher_.publish(model_msg);

//                     cnt++;
//                 }
//             }

//             // record time for next integration
//             last_time_ = current_time_;
//         }

//         ros::spinOnce();
//         rate.sleep();
//     }

//     return 0;
// }








#include <ros/ros.h>
#include "gazebo_msgs/ModelState.h"
#include "gazebo_msgs/ModelStates.h"
#include "geometry_msgs/Twist.h"

#include <iostream>
#include <math.h>

using namespace std;

// Publisher
ros::Publisher obstacle_publisher_;

// Message
gazebo_msgs::ModelState model_msg;
geometry_msgs::Twist tw_msg;
gazebo_msgs::ModelStates model;

// ROS Time
ros::Time last_time_;
ros::Time current_time_;


int main(int argc, char** argv)
{
    ros::init(argc, argv, "moving_obstacle");
    ros::NodeHandle nh_;

    ros::Rate rate(100); // Hz(Control Frequncy)

    obstacle_publisher_ = nh_.advertise<gazebo_msgs::ModelState>("/gazebo/set_model_state", 100);

    unsigned int cnt = 0;

    const double controlPeriod = 0.2; // sec

    while(ros::ok())
    {
        ROS_INFO("moving_obstacle node ...");

        model = *(ros::topic::waitForMessage<gazebo_msgs::ModelStates>("/gazebo/model_states"));

        current_time_ = ros::Time::now();
        double dt = (current_time_ - last_time_).toSec();

        static bool init_run = true;

        if (init_run)
        {
            last_time_ = current_time_;
            init_run = false;
            continue;
        }

        if(!model.name.empty())
        {
            for(int i=0; i<model.name.size(); i++)
            {
                // Find the obstacle name
                if(strcmp(model.name[i].data(), "obstacle") == 0)
                {
                    // cout << "Find!" << endl;

                    std::string model_name = "obstacle";


                     double period = 1.0 / controlPeriod;
                     double mag = 2.0;

                   // Set the state
                    model_msg.model_name = model_name;
                    model_msg.pose = model.pose[i];
                    // model_msg.pose.position.x = 1.0 * sin(2.0*M_PI/period * (double)cnt);

                    cout << "time = " << dt << endl;

                    // model_msg.twist.linear.x = 1.0 * sin(2.0*M_PI/period * (double)cnt);
                    model_msg.twist.linear.x = 0.0;
                    model_msg.twist.angular.z = 3.0 * sin(2.0*M_PI/period * (double)cnt);

                    obstacle_publisher_.publish(model_msg);

                    cnt++;
                }
            }

            // record time for next integration
            last_time_ = current_time_;
        }

        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}







