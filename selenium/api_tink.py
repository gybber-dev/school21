import asyncio
import tinvest
import json

def get_ticker_position(portfolio, ticker):
    for x in portfolio.payload.positions:
        if x.ticker == ticker:
            return x
    return None



async def main(tkn, ticker):
    client = tinvest.AsyncClient(tkn)
    portfolio = await client.get_portfolio()  # tinvest.PortfolioResponse
    position = get_ticker_position(portfolio, ticker)
    print(json.dumps(position.balance, indent=4, sort_keys=True))
    await client.close()
    # return position.balance

tkn = "t.GCXvoLTBa6nau4er-4L_dbtzsclNH3mESje0ASJJM4AtjqbFYToq67Xza6AS7Q8vO7ZllskXwG6IHgLPAfBe2Q"

if __name__ == '__main__':
    try:
        asyncio.run(main(tkn, "TIPO"))
    except KeyboardInterrupt:
        pass