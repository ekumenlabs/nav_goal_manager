
#include <nav_goal_manager/nav_goal_manager.h>

int main(int argc, char** argv) {
  ros::init(argc, argv, "nav_goal_manager");
  nav_goal_manager::NavGoalManager node = nav_goal_manager::NavGoalManager();
  ros::spin();
  return(0);
}
