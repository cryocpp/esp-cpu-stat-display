import psutil,serial
esp = serial.Serial(port="/dev/tty.usbserial-0001",baudrate=9600,timeout=1)
while True:
    cpu_usage = psutil.cpu_percent(1)
    print(cpu_usage)
    perfstring = f"{cpu_usage}\n"
    esp.write(perfstring.encode())


    
