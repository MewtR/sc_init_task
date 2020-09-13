## SC Software Initiation task

### Dependencies
* [flask](https://flask.palletsprojects.com/en/1.1.x/)
* [fortune](https://github.com/shlomif/fortune-mod)
* [ros](http://wiki.ros.org/melodic)

### How it works

Essentially, there is a ros node that publishes messages it gets from the fortune program.
The flask frontend is a very ugly GUI that simply displays those messages.
