"""
A basic flask web app that connects to a weather api.
Author: Alex Breger
Reviewed: Ben Bortkevich
"""

from flask import Flask, render_template, request, url_for, redirect
import os
import requests
from pymongo import MongoClient
from datetime import datetime

client = MongoClient('localhost', 27017)

db = client.flask_db_weather
weather_col = db.weather

if weather_col.count_documents({}) > 0:
    weather_col.delete_many({})

app = Flask(__name__)

# The API key should ideally be provided via an environment variable
# to avoid committing secrets to source control.
SECRET_KEY = os.getenv("OPENWEATHER_KEY", "")
API_CALL = (
    "http://api.openweathermap.org/data/2.5/forecast?q={}&appid={}&units=metric"
)


def get_api_data(city_name):
    try:
        data = requests.get(API_CALL.format(city_name, SECRET_KEY)).json()
        return data
    except Exception as e:
        print(f"Error getting API data {e}")
        return None


def parse_data(response):
    daily_data = {}
    try:
        if response.get("cod") == "200":
            city_name = response["city"]['name']
            country = response['city']["country"]

            for item in response['list']:
                date = datetime.strptime(item['dt_txt'], '%Y-%m-%d %H:%M:%S').strftime('%Y-%m-%d')
                if date not in daily_data:
                    daily_data[date] = {
                        'date': date,
                        'city_name': city_name,
                        'country': country,
                        'temperature': str(item["main"]["temp"]),
                        'humidity': str(item["main"]["humidity"]),
                        'day_temp': str(item["main"]["temp_max"]),
                        'night_temp': str(item["main"]["temp_min"]),
                        'description_weather': item["weather"][0]["description"]
                    }

    except Exception as e:
        print(f"There was an error in the city name or country.{e}")
        return []

    return list(daily_data.values())


@app.route('/', methods=('GET', 'POST'))
def weather():
    if request.method == 'POST':
        city = request.form['content']
        if city:
            response = get_api_data(city)
            weather_data = parse_data(response)
            if weather_data:
                weather_col.delete_many({'city_name': city})
                weather_col.insert_many(weather_data)

        return redirect(url_for('weather'))

    all_weather_info = list(weather_col.find({}, {'_id': 0}))
    return render_template('weather.html', days=all_weather_info)


if __name__ == "__main__":
    app.run(debug=True)

