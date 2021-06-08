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
        'Введите пароль',
        'Банк отправил код подтверждения на номер',
        'Не сообщайте логин, пароль и код подтверждения'
    ]
    # try:
    contents = driver.find_elements_by_css_selector('div[data-qa-file="Container"]')
    entry_page = 'https://www.tinkoff.ru/login/'
    # if it is not entry page:
    if len(contents) == 0 or contents[0].text.find(keywords[3]) == -1:
        print('no content')
        driver.get(entry_page)
        sleep(3)
        contents = driver.find_elements_by_css_selector('div[data-qa-file="Container"]')
        if len(contents) == 0 or contents[0].text.find(keywords[3]) == -1:
            print("Can't reach entry page" + entry_page)
            return 3

    if contents[0].text.find(keywords[0]) != -1:
        print('phone page')
        return 0
    elif contents[0].text.find(keywords[2]) != -1:
        print('code page')
        return 1
    elif contents[0].text.find(keywords[1]) != -1:
        print('psw page')
        return 2
    print("Can't find entry keywords")
    return 3
    # except:
    #     print('error 1')
    #     return 3

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
        elements = driver.find_elements_by_css_selector('input[type="tel"]')
        if not len(elements):
            return False
        elements[0].send_keys(code)
        # submit_buttons = driver.find_elements_by_css_selector('button[type="submit"]')
        # if not len(submit_buttons):
        #     return False
        # submit_buttons[0].click()
    except:
        print("Enter code error")
        return False

def _enter_psw(driver, psw):
    try:
        print('enter psw')
        elements = driver.find_elements_by_css_selector('input[type="password"]')
        if not len(elements):
            return False
        elements[0].send_keys(psw)
        submit_buttons = driver.find_elements_by_css_selector('button[type="submit"]')
        if not len(submit_buttons):
            return False
        submit_buttons[0].click()
    except:
        print("Enter psw error")
        return False

once_flag = 2

def auth(phone, psw, code, id, url):

    for i in range(3):
        print("auth function")
        driver = _connect_to_session(id, url)
        if check_auth(id, url):
            print("Logged in")
            return 0
        page_type = _detect_curret_page(driver)
        if page_type == 0:
            print("page_type == 0")
            if not _enter_phone(driver, phone):
                print("Can't enter phone number")
                break
            else:
                sleep(3)
                continue
        if page_type == 1:
            print("page_type == 1")
            if not code:
                print("Need to code")
                return 1
            else:
                _enter_code(driver, code)
                sleep(10)
                continue
        if page_type == 2:
            print("page_type == 2")
            if not psw:
                print("no password")
                return 2
            else:
                _enter_psw(driver, psw)
                sleep(10)
                continue
        return 3

def sell(page, id, url):
    driver = _connect_to_session(id, url)
    driver.get(page)
    sleep(3)
    sell_buttons = driver.find_elements_by_css_selector('div[data-qa-file="Sticky"] a[href*="sell"]')
    if not len(sell_buttons):
        print('no buttons yet')
        return False
    sell_buttons[0].click()
    sleep(3)
    # market price
    sell_options = driver.find_elements_by_css_selector('label[unselectable="on"]')
    print(sell_options)
    print(len(sell_options))
    if len(sell_options) != 3:
        print("no options yet")
        return False
    sell_options[2].click()
    sleep(3)
    # insert count of product
    countForms = driver.find_elements_by_css_selector('input[data-qa-file="MarketSellFormPure"]')
    if not len(sell_buttons):
        print('no forms yet')
        return False
    countForms[0].send_keys("1")
    sleep(3)
    # click accept button
    accept_buttons = driver.find_elements_by_css_selector('button[data-qa-type="uikit/button"]')
    if not len(accept_buttons):
        print('no apply buttons yet')
        return False
    accept_buttons[0].click()





session = {
    "id": "92d13d1ea03baec13cefa975edb188d5",
    "url": "http://127.0.0.1:49413"
}
# print(check_auth(**session))
status = auth("", "", None, **session)
# print(status)
# if status == 0:
#     sell('https://www.tinkoff.ru/invest/currencies/USDRUB/', **session)

# assert "Python" in driver.title
# elem = driver.find_element_by_name("q")
# elem.send_keys("pycon")
# elem.send_keys(Keys.RETURN)
# assert "No results found." not in driver.page_source
# driver.close()
