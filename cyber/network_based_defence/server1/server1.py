from http.server import BaseHTTPRequestHandler, HTTPServer

class SimpleHTTPRequestHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        self.end_headers()
        self.wfile.write(b'Hello from Server 1')

if __name__ == "__main__":
    server = HTTPServer(('0.0.0.0', 8081), SimpleHTTPRequestHandler)
    server.serve_forever()
