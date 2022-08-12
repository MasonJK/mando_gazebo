# Software Info.  
https://catnip-archive.tistory.com/entry/VMware-VMware%EC%97%90-%EA%B0%80%EC%83%81%EB%A8%B8%EC%8B%A0-%EC%B6%94%EA%B0%80%ED%95%98%EA%B8%B0feat-Ubuntu-1804-LTS    
1. ubuntu : 18.04
2. ROS : melodic version

* if you can not see the gazebo viewer, you should write below command.  
```
$ export SVGA_VGPU10=0
```

* Error in REST request
-> https://wth-mongdol.tistory.com/158

# ROS Library Info.
## 0. Basic Library  
```
$ sudo apt-get install ros-melodic-joy ros-melodic-teleop-twist-joy \
  ros-melodic-teleop-twist-keyboard ros-melodic-laser-proc \
  ros-melodic-rgbd-launch ros-melodic-depthimage-to-laserscan \
  ros-melodic-rosserial-arduino ros-melodic-rosserial-python \
  ros-melodic-rosserial-server ros-melodic-rosserial-client \
  ros-melodic-rosserial-msgs ros-melodic-amcl ros-melodic-map-server \
  ros-melodic-move-base ros-melodic-urdf ros-melodic-xacro \
  ros-melodic-compressed-image-transport ros-melodic-rqt* \
  ros-melodic-gmapping ros-melodic-navigation ros-melodic-interactive-markers
```

## 1. ROS SLAM stack

### 1-1. Gmapping  
```
$ sudo apt-get install ros-melodic-gmapping  
```

### 1-2. Cartographer  
https://google-cartographer-ros.readthedocs.io/en/latest/compilation.html  
```
$ sudo apt-get update
sudo apt-get install -y python-wstool python-rosdep ninja-build stow
```

```
$ mkdir cartographer_ws
cd cartographer_ws
wstool init src
wstool merge -t src https://raw.githubusercontent.com/cartographer-project/cartographer_ros/master/cartographer_ros.rosinstall
wstool update -t src
```

```
$ sudo rosdep init
rosdep update
rosdep install --from-paths src --ignore-src --rosdistro=${ROS_DISTRO} -y
```

```
$ src/cartographer/scripts/install_abseil.sh
```

* if you can see the error, you must remove the line "<depend>libabsl-dev</depend>" in the package.xml (cartographer folder)-  
* error message : ERROR: the following packages/stacks could not have their rosdep keys resolved to system dependencies: cartographer: [libabsl-dev] defined as "not available" for OS version [focal]

```
$ catkin_make_isolated --install --use-ninja
```

## 2. ROS navigation stack  
```
$ sudo apt-get install ros-melodic-navigation
```

## 3. scout_mini_gazebo package  
```
$ git clone ...
```

## 4. teleop keyboard  
```
$ sudo apt install -y ros-$ROS_DISTRO-teleop-twist-keyboard
```
