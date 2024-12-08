import dns.resolver

#with open("all.txt", "r") as f:
#    subdomains = f.readlines()

subdomains = ["www", "mail", "ftp", "test", "dev", "meet", "team", "learn", 'promo', "store", "shop",
"engage", "quote", "landing", "services", "hello", "try", "trial", "demo", "sales"]

domain = "google.co.il"

for subdomain in subdomains:
    full_domain = f"{subdomain}.{domain}"
    try:
        answers = dns.resolver.resolve(full_domain, "A")
        for answer in answers:
            print(f"Subdomain found: {full_domain}: {answer}")
    except dns.resolver.NXDOMAIN:
        pass  # Subdomain does not exist
    except Exception as e:
        print(f"Error resolving {full_domain}: {e}")