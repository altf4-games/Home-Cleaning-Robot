using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;
using UnityEngine.UI;
using TMPro;

public class RobotControl : MonoBehaviour
{
    public string Port = "COM5";
    public TMP_Dropdown comPortDropdown;
    SerialPort serialPort;
    bool autonomousMode = false;

    void Start()
    {
        /*serialPort = new SerialPort(Port, 9600);
        serialPort.Open();*/

        comPortDropdown.ClearOptions();
        List<string> options = new List<string>();

        // Add COM ports from 0 to 12
        for (int i = 0; i <= 12; i++)
        {
            options.Add("COM" + i);
        }

        comPortDropdown.AddOptions(options);

        comPortDropdown.onValueChanged.AddListener(delegate {
            OnCOMPortDropdownValueChanged(comPortDropdown);
        });
    }

    void Update()
    {
        // Toggle autonomous mode when pressing 'A' key
        if (Input.GetKeyDown(KeyCode.A))
        {
            ToggleAutonomousMode();
        }

        // Windows Controls
        if (!autonomousMode)
        {
            if (Input.GetKey(KeyCode.UpArrow))
            {
                MoveForward();
            }
            else if (Input.GetKey(KeyCode.LeftArrow))
            {
                TurnLeft();
            }
            else if (Input.GetKey(KeyCode.RightArrow))
            {
                TurnRight();
            }
            else if (Input.GetKey(KeyCode.DownArrow))
            {
                Stop();
            }
        }
    }

    void OnCOMPortDropdownValueChanged(TMP_Dropdown change)
    {
        string selectedCOMPort = change.options[change.value].text;
        Port = selectedCOMPort;
        serialPort = new SerialPort(Port, 9600);
        serialPort.Open();
        Debug.Log("Selected COM port: " + selectedCOMPort);
    }

    public void ToggleAutonomousMode()
    {
        autonomousMode = !autonomousMode;
        char modeChar = autonomousMode ? 'A' : 'M';
        serialPort.Write(modeChar.ToString());
    }

    public void MoveForward()
    {
        serialPort.Write("F");
    }

    public void TurnLeft()
    {
        serialPort.Write("L");
    }

    public void TurnRight()
    {
        serialPort.Write("R");
    }

    public void Stop()
    {
        serialPort.Write("B");
    }

    void OnApplicationQuit()
    {
        serialPort.Close();
    }
}
