import asyncio
# from pprint import pprint

import tinvest

def get_ticker_position(portfolio, ticker):
    for x in portfolio.payload.positions:
        if x.ticker == ticker:
            return x
    return None



async def get_balance(TOKEN, ticker):
    client = tinvest.AsyncClient(TOKEN)
    portfolio = await client.get_portfolio()  # tinvest.PortfolioResponse
    position = get_ticker_position(portfolio, ticker)
    await client.close()
    return position.balance

# def some_fun():
#     TOKEN = ""
#     print(asyncio.run(get_balance(TOKEN, "TIPO")))

#
# if __name__ == '__main__':
#     # try:
#     print(asyncio.run(get_balance(TOKEN, "TSPV")))
#     # except KeyboardInterrupt:
#     #     pass
some_fun()