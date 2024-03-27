using UnityEngine;
using System.IO.Ports;

public class ArduinoController : MonoBehaviour
{
    SerialPort serialPort;
    public string portName = "COM3";
    public int baudRate = 9600;

    void Start()
    {
        serialPort = new SerialPort(portName, baudRate);
        try
        {
            serialPort.Open();
            Debug.Log("Serial port opened");
        }
        catch (System.Exception e)
        {
            Debug.LogError("Error opening serial port: " + e.Message);
        }
    }

    void Update()
    {
        if (serialPort.IsOpen)
        {
            try
            {
                string message = serialPort.ReadLine();
                Debug.Log("Received from Arduino: " + message);
            }
            catch (System.Exception e)
            {
                Debug.LogError("Error reading from serial port: " + e.Message);
            }
        }
    }

    public void CallArduinoFunction()
    {
        if (serialPort.IsOpen)
        {
            serialPort.WriteLine("A");
        }
    }

    void OnDestroy()
    {
        if (serialPort != null && serialPort.IsOpen)
        {
            serialPort.Close();
            Debug.Log("Serial port closed");
        }
    }
}
