from selenium import webdriver
import json
from time import sleep


def create_session():
    # change for another OS
    driver = webdriver.Chrome('./chromedriver.exe')
    # driver = webdriver.Chrome('./chromedriver')
    driver.get("https://www.tinkoff.ru/login/?redirectTo=%2Finvest%2Fbroker_account%2F&redirectType=")
    return {'url': driver.command_executor._url, 'id': driver.session_id}


# dict = create_session()
# parsed = json.loads(your_json) # from string to dictionary
# print(json.dumps(dict, indent=4, sort_keys=True))


# delete after debugging:
# driver = webdriver.Chrome('./chromedriver.exe')
# driver.get("https://www.tinkoff.ru/login/?redirectTo=%2Finvest%2Fbroker_account%2F&redirectType=")
# dict = {'url': driver.command_executor._url, 'id': driver.session_id}
# print(json.dumps(dict, indent=4, sort_keys=True))


# while True:
#     ()

def check_auth(session):
    driver = webdriver.Remote(command_executor=session['url'], desired_capabilities={})
    driver.close()  # this prevents the dummy browser
    driver.session_id = session['id']
    driver.get("https://www.tinkoff.ru/invest/broker_account/")
    login_buttons = driver.find_elements_by_css_selector('a[href*="/login/"]')

    # there are 3 login links. 1st is "Войти"
    if login_buttons[0].get_attribute('innerText') == "Войти":
        return False
    # there is 1 login link in the bottom
    if len(login_buttons) == 1 and login_buttons[0].get_attribute('innerText') == "Личный кабинет":
        return True
    print("something wrong!!!")
    return False
    # print(tag[0].get_attribute('innerHTML'))
    # print(len(login_button))



def sample(a, b, c):
    """how to unpack variables:"""
    print(a)
    print(b)
    print(c)

# c = {'c': 3, '3': 4}
# d = {'a': 1, 'b': 2, 'c': c}
# sample(**d)

def _connect_to_session(id, url):
    driver = webdriver.Remote(command_executor=url, desired_capabilities={})
    driver.close()  # this prevents the dummy browser
    driver.session_id = id
    return driver

def auth(phone, psw, code, id, url):
    driver = _connect_to_session(id, url)
    print(phone)
    print(code)
    print(psw)




session = {
    "url": "http://127.0.0.1:49468",
    "id": "3591b0bad138390bfef6bff61b3dfaaa"
}

print(check_auth(session))
auth(1, 2, 3, **session)
# assert "Python" in driver.title
# elem = driver.find_element_by_name("q")
# elem.send_keys("pycon")
# elem.send_keys(Keys.RETURN)
# assert "No results found." not in driver.page_source
# driver.close()
