import requests


def req_func():

    url = 'http://google.com'
    res = requests.get(url)
    print(res.status_code)
    print(res.cookies)
    print(res.text)


if __name__ == '__main__':
    req_func()