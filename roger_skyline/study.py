#!/usr/bin/python

from flask import Flask
from flask import render_template, request, session
from flask import redirect, url_for

app = Flask(__name__)

@app.route('/')
def hello_world():
    return 'Hello World!'

@app.route('/main')
def main():
    return 'main page'

@app.route('/user/<username>')
def show_user_profile(username):
    return 'User %s' % username

@app.route('/post/<int:post_id>')
def show_post(post_id):
    return 'Post %d' % post_id

@app.route('/logging')
def logging_test():
    test = 1
    app.logger.debug('debug needed')
    app.logger.warning(str(test) + " line")
    app.logger.error('error')
    return "logging end"

@app.route('/login_form')
def login_form():
    return render_template('login3.html')

@app.route('/login', methods=['POST'])
def login():
	if request.method == 'POST':
		if (request.form['username'] == 'jin'
			and request.form['password'] == '1234'):
			session['logged_in'] = True
			session['username'] = request.form['username']
			return request.form ['username'] + " Welcome"
		else:
			return 'Wrong login information'
	else:
		return 'Worng pathway'

# @app.route('/login', methods=['POST'])
# def login():
# 	render_template('login3.html')
# 	if (request.method == 'POST'):
# 		if (request.form['username'] == 'jin'
# 			and request.form['password'] == '1234'):
# 			session['logged_in'] = True
# 			session['username'] = request.form['username']
# 			return request.form ['username'] + "welcome"
# 		else:
# 			return 'Wrong login information'
# 	else:
# 		return 'error'
    	
@app.route('/logout')
def logout():
		session['logged_in'] = False
		session.pop('username', None)
		return redirect(url_for('login_form'))

app.secret_key = 'abc'

if __name__ == '__main__':
    app.run()