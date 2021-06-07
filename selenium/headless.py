from selenium import webdriver
import json
from time import sleep


def create_session():
    # change for another OS
    # driver = webdriver.Chrome('./chromedriver.exe')
    driver = webdriver.Chrome('./chromedriver')
    driver.get("https://www.tinkoff.ru/login/?redirectTo=%2Finvest%2Fbroker_account%2F&redirectType=")
    return {'url': driver.command_executor._url, 'id': driver.session_id}


# dict = create_session()
# parsed = json.loads(your_json) # from string to dictionary
# print(json.dumps(dict, indent=4, sort_keys=True))





# delete after debugging:
# driver = webdriver.Chrome('./chromedriver')
# driver.get("https://www.tinkoff.ru/login/?redirectTo=%2Finvest%2Fbroker_account%2F&redirectType=")
# dict = {'url': driver.command_executor._url, 'id': driver.session_id}
# print(json.dumps(dict, indent=4, sort_keys=True))


# while True:
#     ()

def check_auth(id, url):
    driver = webdriver.Remote(command_executor=url, desired_capabilities={})
    driver.close()  # this prevents the dummy browser
    driver.session_id = id
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

def _detect_curret_page(driver):
    '''
    :param driver:
    :return:    0 - phone number page
                1 - code page
                2 - psw page
                3 - error page
    '''
    keywords = [
        'Введите номер телефона',
        '',
        'Банк отправил код подтверждения на номер'
    ]
    try:
        contents = driver.find_elements_by_css_selector('div[data-qa-file="Container"]')
        entry_page = 'https://www.tinkoff.ru/login/'
        # if it is not entry page:
        if not len(contents):
            print('no content')
            driver.get(entry_page)
            contents = driver.find_elements_by_css_selector('div[data-qa-file="Container"]')
            if not len(contents):
                print("Can't reach entry page" + entry_page)
                return 3

        if contents[0].text.find(keywords[0]) != -1:
            print('phone page')
            return 0
        elif contents[2].get_attribute('innerText').find(keywords[2]) != -1:
            print('code page')
            return 1
        elif contents[0].get_attribute('innerText').find(keywords[0]) != -1:
            print('psw page')
            return 2
        print("Can't find entry keywords")
        return 3
    except:
        print('error 1')
        return 3

def _enter_phone(driver, phone):
    try:
        elements = driver.find_elements_by_css_selector('input[name="login"]')
        if not len(elements):
            return False
        elements[0].send_keys(phone)
        submit_buttons = driver.find_elements_by_css_selector('button[type="submit"]')
        if not len(submit_buttons):
            return False
        submit_buttons[0].click()
        return True
    except:
        return False

def _enter_code(driver, code):
    try:
        print('enter code')
    except:
        print("Enter code error")
        return False


def auth(phone, psw, code, id, url):
    driver = _connect_to_session(id, url)
    if check_auth(id, url):
        print("Logged in")
        return 0
    if _detect_curret_page(driver) == 0:
        if not _enter_phone(driver, "89178811890"):
            print("Can't enter phone number")
        else:
            # TODO run once!
            auth(phone, psw, code, id, url)
    if _detect_curret_page(driver) == 1:
        if not code:
            print("Need to code")
            return 1
        else:
            _enter_code(driver, code)

    print(phone)
    print(code)
    print(psw)



session = {
    "id": "5598b37f62b6d1c4ca52a416a2b7b2ab",
    "url": "http://127.0.0.1:51297"
}

print(check_auth(**session))
auth(1, 2, 3, **session)
# assert "Python" in driver.title
# elem = driver.find_element_by_name("q")
# elem.send_keys("pycon")
# elem.send_keys(Keys.RETURN)
# assert "No results found." not in driver.page_source
# driver.close()
