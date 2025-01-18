import requests
from bs4 import BeautifulSoup
import json

def scrape_gasbuddy(zip_code):
    """
    Scrapes GasBuddy for fuel prices and station details based on the provided ZIP code.
    """
    url = f"https://www.gasbuddy.com/home?search={zip_code}"
    data = []
    try:
        response = requests.get(url)
        response.raise_for_status()  # Ensure the request was successful
        soup = BeautifulSoup(response.text, 'html.parser')
        
        # Extract stations and fuel details
        stations = soup.find_all('div', class_='styles__priceListItem___3rj7a')
        for station in stations:
            try:
                station_name = station.find('div', class_='styles__stationName___2CzjF').text.strip()
                fuel_type = station.find('div', class_='styles__fuelType___3rKYH').text.strip()
                price = station.find('div', class_='styles__price___3Bc3m').text.strip()
                address = station.find('div', class_='styles__address___2s0cS').text.strip()
                data.append({
                    "station_name": station_name,
                    "fuel_type": fuel_type,
                    "price": price,
                    "address": address
                })
            except AttributeError:
                # Handle cases where some details are missing
                continue
    except Exception as e:
        print(f"Error scraping GasBuddy: {e}")
    return data

def scrape_e85prices(zip_code):
    """
    Scrapes E85Prices.com for station details and prices based on the provided ZIP code.
    """
    url = f"https://www.e85prices.com/{zip_code}"
    data = []
    try:
        response = requests.get(url)
        response.raise_for_status()  # Ensure the request was successful
        soup = BeautifulSoup(response.text, 'html.parser')
        
        # Extract stations and fuel details
        stations = soup.find_all('div', class_='station-info')
        for station in stations:
            try:
                station_name = station.find('h3').text.strip()
                price = station.find('span', class_='price').text.strip()
                address = station.find('p', class_='address').text.strip()
                data.append({
                    "station_name": station_name,
                    "fuel_type": "E85",
                    "price": price,
                    "address": address
                })
            except AttributeError:
                # Handle cases where some details are missing
                continue
    except Exception as e:
        print(f"Error scraping E85Prices: {e}")
    return data

def main():
    zip_code = input("Enter your ZIP code: ").strip()
    all_data = {}

    print("Scraping GasBuddy...")
    gasbuddy_data = scrape_gasbuddy(zip_code)
    all_data['GasBuddy'] = gasbuddy_data

    print("Scraping E85Prices...")
    e85_data = scrape_e85prices(zip_code)
    all_data['E85Prices'] = e85_data

    # Save to file
    save_to_file(all_data)

def save_to_file(data, filename='fuel_prices.json'):
    """
    Saves the scraped data to a JSON file.
    """
    with open(filename, 'w') as file:
        json.dump(data, file, indent=4)
    print(f"Data saved to {filename}")

if __name__ == "__main__":
    main()
