# ESP8266 Wi-Fi and Telegram Messaging Test

## Overview

This project tests Wi-Fi connectivity and sending Telegram messages using an ESP8266 NodeMCU development board.

After connecting to a Wi-Fi network, the ESP8266 sends an HTTP GET request to a Cloudflare Worker, which acts as an intermediary between the microcontroller and the Telegram Bot API.

## Hardware

- ESP8266 NodeMCU development board

## Technologies

- Arduino IDE
- ESP8266 Wi-Fi library
- ESP8266 HTTP Client
- HTTPS
- Cloudflare Workers
- Telegram Bot API

## How It Works

1. The ESP8266 connects to a Wi-Fi network.
2. The onboard LED blinks while the board is connecting.
3. After a successful connection, the board prints its local IP address to the Serial Monitor.
4. The ESP8266 sends a message to a Cloudflare Worker over HTTPS.
5. The Cloudflare Worker processes the request and forwards the message to Telegram.
6. The board prints the HTTP status code and server response to the Serial Monitor.

## Why Cloudflare Workers?

The main goal of this project was to test whether an ESP8266 could send Telegram messages despite network restrictions affecting direct access to Telegram from Iran.

Cloudflare Workers was used as an intermediary between the ESP8266 and the Telegram Bot API. The ESP8266 sends an HTTPS request to the Worker, which then forwards the message to Telegram.

This approach was explored as a way to work around connectivity restrictions while keeping the implementation lightweight enough for a microcontroller with limited resources.

## Security Notes

- Wi-Fi credentials should not be published in the source code.
- Telegram bot tokens should be stored as server-side secrets, not exposed in public repositories.
- The current test code uses `client.setInsecure()`, which disables TLS certificate verification. This is convenient for testing but does not securely authenticate the server. Production code should validate the server certificate.

## Purpose

This is a basic IoT communication experiment demonstrating Wi-Fi connectivity, HTTPS requests, cloud-based message forwarding, and Telegram integration.
