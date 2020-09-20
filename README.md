## SC Software Initiation task

### Dependencies
* [flask](https://flask.palletsprojects.com/en/1.1.x/)
* [fortune](https://github.com/shlomif/fortune-mod)
* [ros](http://wiki.ros.org/melodic)

### How it works

Essentially, there is a ros node that publishes messages it gets from the fortune program.
The flask frontend is a very ugly GUI that simply displays those messages.

### How to run it
* Get `roscore` and `rosbridge` going:
  * `roscore`
  * `roslaunch rosbridge_server rosbridge_websocket.launch`
* Get the flask server going:
  * (inside the `front` directory): `export FLASK_APP=subscriber.py`
  * (still inside the `front` directory) `flask run`
  * visit `http://localhost:5000`
* Finally the publisher node:
  * `rosrun initiation_task publisher`

At this point you should see different quotes in the GUI (they change every second).
  
