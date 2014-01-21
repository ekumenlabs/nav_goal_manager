nav_goal_manager
================

This package provides a "gateway" node to movebase. This allows a simple
client, not actionlib based, to send nav goals and cancel them.

Move_base provides the simple interface, which allows a client to send
goals without using Actionlib. However, cancelation is not possible with
move base alone.
