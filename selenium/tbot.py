# import apitink
import asyncio
import json
import telebot
import tinvest

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




# bot.polling(none_stop=True)
@bot.message_handler(commands=['start'])
def start_command(message):
    print("start fun")
    tkn = get_tocken(message.from_user.id)
    print(asyncio.run(get_balance(tkn, "TIPO")))
    bot.send_message(
        message.chat.id,
        'Greetings! I can show you exchange rates.\n' +
        'To get the exchange rates press /exchange.\n' +
        'To get help press /help.'
  )
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