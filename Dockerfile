FROM ros:melodic

SHELL ["/bin/bash", "-c"]
RUN mkdir -p /catkin_ws/src/initiation_task

WORKDIR /catkin_ws

ENV PATH="/usr/games:${PATH}"

RUN source /opt/ros/$ROS_DISTRO/setup.sh && \
    apt-get update && apt-get install -y fortune-mod && \
    catkin_make -DPYTHON_EXECUTABLE=/usr/bin/python 

WORKDIR /catkin_ws/src/initiation_task

COPY . .

WORKDIR /catkin_ws

RUN source /opt/ros/$ROS_DISTRO/setup.sh \
    && catkin_make \
    && source devel/setup.bash \
    && chmod u+x /catkin_ws/src/initiation_task/docker/publisher/entrypoint.sh

ENTRYPOINT ["/catkin_ws/src/initiation_task/docker/publisher/entrypoint.sh"]
    
