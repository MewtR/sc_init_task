from flask import Flask
from flask import render_template
app = Flask(__name__)

@app.route('/')
def hello_world():
    msg = 'Random Quotes'
    return render_template('subscriber.html', msg=msg)
