const puppeteer = require('puppeteer');

async function connectToBrowser() {
  const browserURL = 'http://127.0.0.1:21222';
  const browser = await puppeteer.connect({browserURL}); 
  const pages = await browser.pages();
  const page = pages[pages.length - 1]
  await page.goto('https://www.tinkoff.ru/invest/currencies/USDRUB/'); 
  
  // sell button
  const [response] = await Promise.all([
    page.waitForNavigation(),
    page.click('a[href*="/invest/currencies/USDRUB/sell/"]'),
  ]);
}

connectToBrowser();