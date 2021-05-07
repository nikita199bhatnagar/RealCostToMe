import http.server
import socketserver
import os
import subprocess
from urllib.parse import urlparse
from urllib.parse import parse_qs

class MyHttpRequestHandler(http.server.SimpleHTTPRequestHandler):
    def do_GET(self):
        # Sending an '200 OK' response
        self.send_response(200)

        # Setting the header
        self.send_header("Content-type", "text/html")

        # Whenever using 'send_header', you also have to call 'end_headers'
        self.end_headers()
        html = ""
        # Extract query param
        query_components = parse_qs(urlparse(self.path).query)
        if 'amount' in query_components:
            amount = query_components["amount"]
            roi = query_components["roi"]
            term = query_components["term"]
            days = query_components["days"]
            print(amount, roi, term, days)
            val = subprocess.check_output(["handler.exe", str(amount[0]),str(roi[0]), str(term[0]), str(days[0])])
            html = f"<html><head></head><body><h1>Hello world!</br>Interest:{val}</h1></body></html>"
        else:
            html = f"<html><head></head><body><h1>Hello world!</h1></body></html>"
            
      #localhost:8000/?amount=10000&roi=7&term=1&days=45

        # Writing the HTML contents with UTF-8
        self.wfile.write(bytes(html, "utf8"))

        return

# Create an object of the above class
handler_object = MyHttpRequestHandler

PORT = 8000
my_server = socketserver.TCPServer(("", PORT), handler_object)

# Star the server
my_server.serve_forever()


#import os 
#import subprocess
#amount = 10000
#roi = 7
#term = 1
#days = 45
#val = subprocess.check_output(['F:/RealCost/RealCostToMe/handler.exe', 'amount', 'roi', 'term', 'days'])
#val = subprocess.check_output(['handler.exe', '10000', '7', '1', '45'])