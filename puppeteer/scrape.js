const puppeteer = require('puppeteer');

let runBrowser = async () => {
    try{

        const browser = await puppeteer.launch({
            headless: false,
            args: [
                '--remote-debugging-port=21222'
            ]
        });
        const page = await browser.newPage();
        await page.goto('https://www.tinkoff.ru/invest/stocks/?auth=null&large=null');
        await page.waitFor(60000);
        
        // browser.close();
        await open_paper({page});
        return result;
    }catch(e)
        {console.log(e)};
};

// Можно вставить таймер в div с параметрами:
// data-qa-file="PortalContainer"


async function open_paper(params){
    try{
        console.log("actions....");
        await params.page.goto("https://www.tinkoff.ru/invest/etfs/TIPO/");
        await params.page.waitFor(5000);
        // let buyButton = document.querySelector('a[href*="/invest/etfs/TIPO/buy/"]');
        // let sellButton = document.querySelector('a[href*="/invest/etfs/TIPO/sell/"]');
        
        // Click on Sell button
        const [response] = await Promise.all([
            params.page.waitForNavigation(),
            params.page.click('a[href*="/invest/etfs/TIPO/sell/"]'),
          ]);

        // const [response] = await Promise.all([
        //     params.page.waitForNavigation(),
        //     params.page.click('a[href*="/invest/etfs/TIPO/sell/"]'),
        //   ]);





        console.log("Done");
    }catch(e){console.log(e)}
}

runBrowser().then((value) => {
    console.log(value); // Получилось!
});