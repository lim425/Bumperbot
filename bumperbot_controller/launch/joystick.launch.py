from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument

import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():

    use_sim_time_arg = DeclareLaunchArgument(
        "use_sim_time",
        default_value="True",
    )

    use_sim_time = LaunchConfiguration('use_sim_time')

    joy_params = os.path.join(get_package_share_directory('bumperbot_controller'),'config','joystick.yaml')

    joy_node = Node(
            package='joy',
            executable='joy_node',
            parameters=[joy_params, {'use_sim_time': use_sim_time}],
         )

    teleop_node = Node(
            package='teleop_twist_joy',
            executable='teleop_node',
            name='teleop_node',
            parameters=[joy_params, {'use_sim_time': use_sim_time}],
            # remappings=[('/cmd_vel','/bumperbot_controller/cmd_vel')]
         )
    
    twist_stamper = Node(
            package='bumperbot_controller',
            executable='twist_to_twiststamped.py',
            name="twist_to_twiststamped"
         )

    return LaunchDescription([
        use_sim_time_arg,
        joy_node,
        teleop_node,
        twist_stamper       
    ])