# import apitink
import asyncio
import json
import telebot
import tinvest
import headless


bot = telebot.TeleBot("1880314498:AAGEPrpOTzZH_0zzwcaZgdkoEPShohgF_tM")

def read_file(file):
    f = open(file, 'r+')
    data = json.load(f)
    f.close()
    return data

def write(file, data):
    with open(file, "w") as outfile:
        json.dump(data, outfile)
    outfile.close()

def get_tocken(id):
    id = str(id)
    data = read_file("data.json")
    print(type(data))
    print(json.dumps(data[id]["tkn"], indent=4, sort_keys=True))
    return data[id]["tkn"]

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

def sell_ticker(id):
    id = str(id)
    data = read_file("data.json")
    print(data)
    print(id)
    if data[id]["session"]["id"] == None or data[id]["session"]["url"] == None:
        data[id]["session"] = headless.create_session()
        # write(".data.json", data)
        # telebot
    # if not headless.check_auth(**data[id]["session"]):
    #     status = headless.auth(data[id]["phone"], data[id]["psw"], None, **data[id]["session"])
    #     print(status)
        # if status == 1:


    # headless.check_auth()




# bot.polling(none_stop=True)
# def email_create_request_data(message):



@bot.message_handler(commands=['start'])
def start_command(message):
    print("start fun")
    print(message)
    # print(json.dumps(message, indent=4, sort_keys=True))
    tkn = get_tocken(message.from_user.id)
    balance = asyncio.run(get_balance(tkn, "TIPO"))
    keyboard = telebot.types.InlineKeyboardMarkup()
    keyboard.row(
        telebot.types.InlineKeyboardButton('Sell TIPO', callback_data='sell')
    )
    # keyboard.row(
    #     telebot.types.InlineKeyboardButton('buy', callback_data='get-EUR'),
    #     telebot.types.InlineKeyboardButton('sell', callback_data='get-RUR')
    # )
    # print(message.data)
    ss = bot.send_message(
        message.chat.id,
        'Your balance: ' + str(balance),
        reply_markup=keyboard
    )
    bot.register_next_step_handler(ss, print)



@bot.callback_query_handler(func=lambda call: True)
def ans(message):
    print(message)
    if message.data == "sell":
        sell_ticker(message.from_user.id)






@bot.message_handler(commands=['help'])
def help_command(message):
    keyboard = telebot.types.InlineKeyboardMarkup()
    keyboard.add(
        telebot.types.InlineKeyboardButton(
            'Message the developer', url='telegram.me/artiomtb'
  )
    )
    bot.send_message(
        message.chat.id,
        '1) To receive a list of available currencies press /exchange.\n' +
        '2) Click on the currency you are interested in.\n' +
        '3) You will receive a message containing information regarding the source and the target currencies, ' +
        'buying rates and selling rates.\n' +
        '4) Click “Update” to receive the current information regarding the request. ' +
        'The bot will also show the difference between the previous and the current exchange rates.\n' +
        '5) The bot supports inline. Type @<botusername> in any chat and the first letters of a currency.',
        reply_markup=keyboard
    )


@bot.message_handler(commands=['exchange'])
def exchange_command(message):
    keyboard = telebot.types.InlineKeyboardMarkup()
    keyboard.row(
        telebot.types.InlineKeyboardButton('USD', callback_data='get-USD')
    )
    keyboard.row(
        telebot.types.InlineKeyboardButton('EUR', callback_data='get-EUR'),
        telebot.types.InlineKeyboardButton('RUR', callback_data='get-RUR')
    )

    bot.send_message(
        message.chat.id,
        'Click on the currency of choice:',
        reply_markup=keyboard
    )

if __name__ == '__main__':
     bot.infinity_polling()