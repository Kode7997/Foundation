from functools import wraps
from flask import Flask, jsonify, request

app = Flask(__name__)

def requires_auth(f):
    @wraps(f)
    def decorated(*args, **kwargs):
        auth = request.authorization
        if  not auth or not auth.username or not auth.password:
            return jsonify({"error": "authentication required"}), 401
        return f(*args, **kwargs)
        
    return decorated

def require_2FA(f):

    def decorated(*args, **kwargs):

        if True:
            return jsonify({"login":"successful"})
        return f(*args, **kwargs)

    return decorated


@app.route('/')
@require_2FA
def home():
    return "welcome to GEEK WORLD"

def guest_house():
    pass


if __name__ == "__main__":
    app.run()