import asyncio
from pprint import pprint

import tinvest

TOKEN = "t.PLwZb6SRcQDAMlDbxpKZ1ScJx3W22Z34os4LHd2QpnHr4YM5eSDHp9Xb3N3RlToH8NzbKLQoL-uUXKkg41Qh4Q"

def get_ticker_position(portfolio, ticker):
    pprint(portfolio.payload.positions)
    for x in portfolio.payload.positions:
        if x.ticker == ticker:
            pprint(x.average_position_price)
            return x
    return None



async def main():
    client = tinvest.AsyncClient(TOKEN)
    portfolio = await client.get_portfolio()  # tinvest.PortfolioResponse
    position = get_ticker_position(portfolio, "TSPV")
    if position and position.balance > 0:
        if position.average_position_price.value > 0.095:
            print("sell them all")
        else:
            print("buy them")
    else:
        print("bye")



    await client.close()

if __name__ == '__main__':
    try:
        asyncio.run(main())
    except KeyboardInterrupt:
        pass