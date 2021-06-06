const puppeteer = require('puppeteer');
async function main() {
const browser = await puppeteer.launch({
headless: false,
args: ['--no-sandbox']
});
const page = await browser.newPage();
await page.goto('https://example.com');
await page.screenshot({
path: 'example.png'
});
await browser.close();
}

// Start the script
main();