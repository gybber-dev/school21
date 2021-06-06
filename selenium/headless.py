from selenium import webdriver
from time import sleep

driver = webdriver.Chrome('./chromedriver')
driver.get("http://www.example.com")

url = driver.command_executor._url
print(url) # http://127.0.0.1:51469
session_id = driver.session_id
print(session_id) #64701c16065c9025667ad1b7e0055e3c

sleep(5)
print("check")
driver = webdriver.Remote(command_executor=url, desired_capabilities={})
driver.close()   # this prevents the dummy browser
driver.session_id = session_id
driver.get("https://www.tinkoff.ru/invest/broker_account/")







# assert "Python" in driver.title
# elem = driver.find_element_by_name("q")
# elem.send_keys("pycon")
# elem.send_keys(Keys.RETURN)
# assert "No results found." not in driver.page_source
# driver.close()