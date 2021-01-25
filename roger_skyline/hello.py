#!/usr/bin/python

# from flask import Flask
# from flask import request
# from flask import render_template
# from flask import session
# from flask import redirect, url_for

# app = Flask(__name__)
# #__name__이 __main__이라는 값을 가지게 되면 해당 모듈이 주 프로그램이라는 의미
# #이렇게 app이라는 변수로 Flask모듈을 쓸 수 있도록 하는것?

# @app.route('/')
# def hello_world():
#     	return 'hello world!'

# @app.route('/main')
# def main():
#     	return 'Main Page'

# @app.route('/user/<username>')
# def showUserProfile(username):
# 		app.logger.debug('RETRIEVE DATA - USER ID : %s' % username)
# 		app.logger.debug('RETRIEVE DATA - Check Compelete')
# 		app.logger.warn('RETRIEVE DATA - Warning... User Not Found.')
# 		app.loger.error('RETIEVE DATA - User unauthenification.')
# 		return ('USER : %s' % username)

# @app.route('user/id/<int:userId>')
# def showUserProfileById(userId):
# 		return ('USER ID : %d' % userId)

# @app.route('/account/login', methods=['POST'])
# def login():
# 		if request.method == 'POST':
# 			userId = request.form['id']
# 			wp = request.form['wp']

# 			if len(userId) == 0 or len(wp) == 0:
# 				return userId+', '+wp+' fail to login'
# 			session['logFlag'] = True
# 			session['userId'] = userId
# 			return 'Welcome' + session['userId']
# 		else:
#     			return 'Try again'

# app.secret.key = 'sample_secret_key'

# @app.route('/user', methods=['GET'])
# def get_User():
    	
# 		if session.get('logFlag') != True:
# 			return 'Wrong'

# 		userId = session['userId']
# 		return '[GET][USER] USER ID : {0}'.format(userId)

# @app.route('/account/logout', methods=['POST','GET'])
# def logout():
# 		session['logFlag'] = False
# 		session.pop('userId', None)
# 		return redirect(url_for('main'))

# @app.errorhandler(400)
# def uncaughtError(error):
# 	return 'Unvalid method'

# # @app.route('/user', methods=['GET'])
# # def get_User():
# # 		if 'userId' in session:
# # 			return '[GET][USER] USER ID : {0}'.format(session['userId'])
# # 		else:
# #     			abort(400)

# @app.handler(404)
# def not_found(error):
# 		resp = make_response(render_template('error.html'), 404)
# 		resp.handers['X-Something'] = 'A value'
# 		return resp

# @app.route('/login', methods=['POST', 'GET'])
# def login_direct():
# 		if request.method == 'POST':
# 			return redirect(url_for('login'), code=307)
# 		else:
# 			return redirect(url_for('login'))
# def valid_login(username, password):
# 		if username != 'jin':
# 			return False
# 		else:
# 			if password != '0000':
# 				return False
# 			return True

# @app.route('/login', methods=['POST', 'GET'])
# def login():
# 	error = None
	
# 	if request.method == 'POST':
# 		if valid_login(request.form['username'], request.form['password']):
# 			return "you are in!"
# 		else:
# 			error = 'Invalid username/password'
# 	return render_template('login.html', error=error)