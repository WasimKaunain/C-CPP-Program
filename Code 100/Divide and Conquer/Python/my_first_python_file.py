from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.options import Options
import pandas as pd

base_url = "https://www.bbc.com/business/technology-of-business"

driver = webdriver.Chrome()
driver.get(base_url)

link =[]

next_button = driver.find_elements(By.CSS_SELECTOR, '[data-testid="pagination-next-button"]')
if len(next_button) != 1:
    print(f"Some problem with link: {base_url}")

next_button[0].click()

div1 = driver.find_elements(By.CSS_SELECTOR, '[data-testid="alaska-grid"]')
if len(div1) != 1:
    print(f"Some problem with link: {base_url}")

tag_a = div1[0].find_elements(By.TAG_NAME, 'a')
if len(tag_a) < 1:
    print(f"Some problem with link: {base_url}")

for i in range(len(tag_a)):
    link.append(tag_a[i].get_attribute("href"))

driver.close()

df = pd.DataFrame(columns=["url"])

for i in range(len(link)):
    df.loc[len(df)] = [link[i]]

df