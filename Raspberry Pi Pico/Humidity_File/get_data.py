import serial
import matplotlib.pyplot as plt 

# Get Data
port = "COM3"
baud_rate = 115200
data_file = "Humidity_Data.txt"
 
try:
    # Open Serial connection
    with serial.Serial(port, baud_rate, timeout=1) as ser, open(data_file, "w") as file:
        print(f"Initializing...")
        # Read line
        while True:
            # Decode bytes to string and strip blank spaces or new line chars
            line = ser.readline().decode('utf-8').strip()
            if line:
                print(f"Data read: {line}")
                file.write(line + "\n")
                file.flush()

except serial.SerialException as e:
    print(f"Communication error: {e}")
except KeyboardInterrupt:
    print("\nExiting and showing graph.")


# Create Graph
x = []
y = []

# Read lines in the file
for line in open('Humidity_Data.txt', 'r'): 
    lines = [i for i in line.split()]   # Separate data from string read 
    x.append(lines[0])  # X axis is the first value read (time) 
    y.append(float(lines[1]))   # Y axis is the 2nd value read (%RH)
plt.title("Humidity ") 
plt.xlabel('Time') 
plt.ylabel('%RH')
plt.gca().set_xticks([])    # Hide x axis values
plt.plot(x, y, marker = ',', c = 'b')   # Create plot with x and y, blue color and just a pixel for the line

plt.show()
