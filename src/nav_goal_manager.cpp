
#include <nav_goal_manager/nav_goal_manager.h>

namespace nav_goal_manager {
  NavGoalManager::NavGoalManager() {
    // Connect to the move_base action server
    actionClient = new ActionClient("move_base", true); // create a thread to handle subscriptions.
    actionClient->waitForServer();

    // Subscribe to the simple goal message.
    ros::NodeHandle goal_sub_nh("nav_manager");
    goal_sub_ = goal_sub_nh.subscribe<geometry_msgs::PoseStamped>("goal", 1, boost::bind(&NavGoalManager::goalSimple, this, _1));
  }

  void NavGoalManager::goalSimple(const geometry_msgs::PoseStamped::ConstPtr& goal) {
    ROS_DEBUG_NAMED("nav goal manager","Goal Callback. Resending to move_base.");
    // We should cancel previous goals here.
    move_base_msgs::MoveBaseGoal action_goal;
    action_goal.target_pose.header = goal->header;
    action_goal.target_pose.pose = goal->pose;
    actionClient->sendGoal(action_goal,
                           boost::bind(&NavGoalManager::doneCallback, this, _1, _2),
                           ActionClient::SimpleActiveCallback(),
                           ActionClient::SimpleFeedbackCallback());
  }

  void NavGoalManager::doneCallback(const actionlib::SimpleClientGoalState &state,
                                    const move_base_msgs::MoveBaseResultConstPtr &result) {
  }

}
