from flask import Flask, request
from time import ctime

app = Flask(__name__)


@app.route('/')
def index_():
    return 'Ok.'


@app.route('/light', methods=['POST', 'GET'])
def light():
    """
    Path for the requests made to url/light, light data.
    :return: Ok.
    """
    data = request.get_data()
    print(ctime() + ", " + str(int(data)), file=open("light_log.txt", "a"))
    return "Ok."


if __name__ == '__main__':
    with open("light_log.txt", "w") as file:
        file.write("time, light\n")
    app.config['HOST'] = '0.0.0.0'
    app.run(host='0.0.0.0', debug=True, port=80)
