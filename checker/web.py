#! /usr/python3
# encoding=utf-8
import flask

app = flask.Flask(__name__)

method = ["POST"]


@app.route("/")
def index():
    return "Genshin Impact"


app.run()
