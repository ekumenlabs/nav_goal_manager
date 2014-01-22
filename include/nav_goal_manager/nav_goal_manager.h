#ifndef NAV_GOAL_MANAGER_H_
#define NAV_GOAL_MANAGER_H_

#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/simple_client_goal_state.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <geometry_msgs/PoseStamped.h>

namespace nav_goal_manager {

  typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> ActionClient;

  class NavGoalManager {
    public:
      /**
       * @brief: Constructor for the goal manager.
       */
      NavGoalManager();

      /**
       * @brief: Handler for new goals sent to the basic interface.
       */
      void goalSimple(const geometry_msgs::PoseStamped::ConstPtr& goal);

     private:
      ActionClient* actionClient;
      ros::Subscriber goal_sub_;
      // Probably some internal helper methods.
      void doneCallback(const actionlib::SimpleClientGoalState &state,
                        const move_base_msgs::MoveBaseResultConstPtr &result);
  };
}

#endif
