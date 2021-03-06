// Sample of Gateware Middleware utilizing D3D11, designed as a potential template project for Project & Portfolio IV students.
// Gateware is a very powerful set of multi-platfrom Middleware libraries, however we are Still in BETA so expect a few bugs here & there.
// Author: Lari H Norri, Full Sail University [Template Version 0.3 Alpha 11/22/2017]
// FYI, I wrote this thing in roughly an hour & a half.(including fixing some bugs) Gateware is pretty slick once you learn how to use it.
// Special Thanks: Andre Reid, Shou-Yi Chang, Daniel Lima and the rest of the Gateware team!

#include <iostream>
// Main Gateware Interface for window creation, check out the included docs on how to use Gateware to the fullest!
#include "Gateware Redistributable R4a/Interface/G_System/GWindow.h"
// Quick & Dirty library link, better to use project properties to support debug & release + 64 & 32 bit builds.
#pragma comment(lib, "Gateware Redistributable R4a/Archive/Win32/Gateware_i386/Debug/GWindow.lib")
// Gateware also has full implicit/explicit DLL support(recommended) & Direct Source code support if desired. 

// Include Our DX11 Class for drawing
#include "LetsDrawSomeStuff.h" // 90% of Gateware is cross-platform, the stuff in this file is not just FYI. (see GOpenGLSurface instead)

// Gateware namespaces here
using namespace GW;
using namespace CORE;
using namespace SYSTEM;

// used to end the program
bool RunApplication = true;

// forward declare event responder
class MyGatewareEventProcessor;
// Used only to keep main() at the top for easy reading
MyGatewareEventProcessor* AllocListener();
void FreeListener(MyGatewareEventProcessor** freeMe);
std::vector<std::thread> ThreadVector;

// Main entry point
int main()
{
	// Handle to our new window, be sure to DecrementCount to free memory
	GWindow* myWindow = nullptr;
	// Used to listen to our new window
	MyGatewareEventProcessor *myListener = AllocListener();
	// Our class that contains all D3D11 related Code
	LetsDrawSomeStuff* myDrawSystem = nullptr;
	float camX = -84.5f, camY = 15.6f, camZ = 180.6f, camP = 145, camYaw = 10, camR = 0,
		planeN = 0.1f, planeF = 500000, cameraSpeed = .1f,
		FOV = 4;
	unsigned int clientWidth = 1024;
	unsigned int clientHeight = 768;
	// Create new window
	if (G_SUCCESS(CreateGWindow(100, 100, 1024, 768, GWindowStyle::WINDOWEDBORDERED, &myWindow)))
	{
		// Register our custom event lister to find out what is going on with the window
		myWindow->RegisterListener(reinterpret_cast<GListener*>(myListener), 0); // listen for any event
		
		// Create our Draw system now that we have a window that is open.
		myDrawSystem = new LetsDrawSomeStuff(myWindow);

		// Show the window if not already being displayed
		if (G_SUCCESS(myWindow->OpenWindow()) || myWindow->OpenWindow() == REDUNDANT_OPERATION)
		{
			// main loop
			while (RunApplication)
			{
				// process platform specific window events
				if (G_FAIL(myWindow->ProcessWindowEvents()))
					break; // nope...

				myWindow->GetClientWidth (clientWidth);
				myWindow->GetClientHeight(clientHeight);

				myDrawSystem->m_Camera->SetPosition(camX, camY, camZ);
				myDrawSystem->m_Camera->SetRotation(camP, camYaw, camR);
				myDrawSystem->rotation += .001f;
				myDrawSystem->translation += .01f;
				myDrawSystem->orbit += .001f;
				myDrawSystem->nearPlane = planeN;
				myDrawSystem->farPlane = planeF;
				myDrawSystem->zoomFOV = FOV;
				myDrawSystem->width = clientWidth;
				myDrawSystem->height = clientHeight;

				if (myDrawSystem->translation > 0)
				{
					myDrawSystem->translation = -15;
				}

				#pragma region Keyboard Camera Position

				if (GetAsyncKeyState(VK_LEFT))//Left
				{
					camX -= cameraSpeed;
					cout << "Position: " << camX << ", " << camY << ", " << camZ << "\n";
					cout << "Rotation: " << camP << ", " << camYaw << ", " << camR << "\n";
				}
				if (GetAsyncKeyState(VK_RIGHT))//Right
				{
					camX += cameraSpeed;
					cout << "Position: " << camX << ", " << camY << ", " << camZ << "\n";
					cout << "Rotation: " << camP << ", " << camYaw << ", " << camR << "\n";
				}
				
				if (GetAsyncKeyState(VK_UP))//Up
				{
					camY += cameraSpeed;
					cout << "Position: " << camX << ", " << camY << ", " << camZ << "\n";
					cout << "Rotation: " << camP << ", " << camYaw << ", " << camR << "\n";
				}
				if (GetAsyncKeyState(VK_DOWN))//Down
				{
					camY -= cameraSpeed;
					cout << "Position: " << camX << ", " << camY << ", " << camZ << "\n";
					cout << "Rotation: " << camP << ", " << camYaw << ", " << camR << "\n";
				}

				if (GetAsyncKeyState(VK_SHIFT))//Back
				{
					camZ -= cameraSpeed;
					cout << "Position: " << camX << ", " << camY << ", " << camZ << "\n";
					cout << "Rotation: " << camP << ", " << camYaw << ", " << camR << "\n";
				}

				if (GetAsyncKeyState(VK_SPACE))//Forward
				{
					camZ += cameraSpeed;
					cout << "Position: " << camX << ", " << camY << ", " << camZ << "\n";
					cout << "Rotation: " << camP << ", " << camYaw << ", " << camR << "\n";
				}

				#pragma endregion

				#pragma region Keyboard Camera Rotation

				if (GetAsyncKeyState(0x41))//A
				{
					camP += 0.1f;
					cout << "Position: " << camX << ", " << camY << ", " << camZ << "\n";
					cout << "Rotation: " << camP << ", " << camYaw << ", " << camR << "\n";
				}
				if (GetAsyncKeyState(0x44))//D
				{
					camP -= 0.1f;
					cout << "Position: " << camX << ", " << camY << ", " << camZ << "\n";
					cout << "Rotation: " << camP << ", " << camYaw << ", " << camR << "\n";
				}

				if (GetAsyncKeyState(0x57))//W
				{
					camYaw -= 0.1f;
					cout << "Position: " << camX << ", " << camY << ", " << camZ << "\n";
					cout << "Rotation: " << camP << ", " << camYaw << ", " << camR << "\n";
				}
				if (GetAsyncKeyState(0x53))//S
				{
					camYaw += 0.1f;
					cout << "Position: " << camX << ", " << camY << ", " << camZ << "\n";
					cout << "Rotation: " << camP << ", " << camYaw << ", " << camR << "\n";
				}

				if (GetAsyncKeyState(0x51))//Q
				{
					camR += 0.1f;
					cout << "Position: " << camX << ", " << camY << ", " << camZ << "\n";
					cout << "Rotation: " << camP << ", " << camYaw << ", " << camR << "\n";
				}

				if (GetAsyncKeyState(0x45))//E
				{
					camR -= 0.1f;
					cout << "Position: " << camX << ", " << camY << ", " << camZ << "\n";
					cout << "Rotation: " << camP << ", " << camYaw << ", " << camR << "\n";
				}

				#pragma endregion

				#pragma region Keyboard Plane Position
				if (GetAsyncKeyState(0x55))//U increase near plane
				{
					planeN += 10;
				}
				if (GetAsyncKeyState(0x49) && planeN > 0.1f)//I decrease near plane
				{
					planeN -= 10;
				}

				if (GetAsyncKeyState(0x4f))//O increase far plane
				{
					planeF += 10;
				}

				if (GetAsyncKeyState(0x50) && planeF > planeN + 10)//P decrease far plane
				{
					planeF -= 10;
				}
#pragma endregion

				#pragma region Keyboard Zooming
				if (GetAsyncKeyState(0x54))//T increases FOV
				{
					FOV += 0.1f;
				}

				if (GetAsyncKeyState(0x59) && FOV > 1.1f)//Y decreases FOV
				{
					FOV -= 0.1f;
				}
#pragma endregion 

				#pragma region Keyboard Scene Changing

				if (GetAsyncKeyState(0x31))//1 switches to first scene
				{
					myDrawSystem->sceneIndex = 0;
					camX = -84.5f, camY = 15.6f, camZ = 180.6f, camP = 145, camYaw = 10, camR = 0;
				}

				if (GetAsyncKeyState(0x32))//2 switches to second scene
				{
					myDrawSystem->sceneIndex = 1;
					camX = -71, camY = 76, camZ = -220, camP = 18, camYaw = 7, camR = 0;
				}

				if (GetAsyncKeyState(0x33))//3 switches to third scene
				{
					myDrawSystem->sceneIndex = 2;
					camX = -931, camY = 620, camZ = 643, camP = 111, camYaw = 33, camR = 0;
				}

#pragma endregion

				// Before or after events are processed lets do some drawing

				//for (auto& thread : ThreadVector)
				//{
				//	thread.join();
				//}
				
				myDrawSystem->Render();
				myDrawSystem->Execute();
			}
		}
		// Free drawing system and all internal elements
		if (myDrawSystem)
		{
			delete myDrawSystem; 
			myDrawSystem = nullptr;
		}

		// Unregister our custom event listner
		myWindow->DeregisterListener(reinterpret_cast<GListener*>(myListener));
		// free window
		FreeListener(&myListener);
		//myWindow->DecrementCount();
		// delete listener (never do this for true gateware interfaces, use "DecrementCount" instead)
	}
    return 0;
}

// Used to process any Gateware Interface events
class MyGatewareEventProcessor : public GListener
{
public:
	// Override required GInterface functions & ignore since this class is not meant to be used by anyone else
	GReturn GetCount(unsigned int &outCount) { return FAILURE;  }
	GReturn IncrementCount() { return FAILURE;  }
	GReturn DecrementCount() { return FAILURE;  }
	GReturn RequestInterface(const GUUIID &ID, void** outInterface) { return FAILURE; }

	// Override The function that actaully matters for listening
	GReturn OnEvent(const GUUIID& senderID, unsigned int eventID, void* eventData, unsigned int eventDataSize)
	{
		// process any GWindow Events
		if (senderID == GWindowUUIID)
		{
			// play it safe
			if (eventDataSize == sizeof(GWINDOW_EVENT_DATA))
			{
				// Copy event
				GWINDOW_EVENT_DATA eventInfo = *reinterpret_cast<GWINDOW_EVENT_DATA*>(eventData);
				// Process specific event
				switch (eventID)
				{
					// stop the main loop
				case GWindowInputEvents::DESTROY:
					RunApplication = false; 
					break;
					// TODO: React to other GWindow events here
				}
			}
		};
		// TODO: Listen for other Gateware Broadcasting Intefaces here

		return SUCCESS; // hopefully we did what we needed to
	}
};

// Delay creation until we know what the above class is (not truly needed just keeps main up top)
MyGatewareEventProcessor* AllocListener() { return new MyGatewareEventProcessor(); }
void FreeListener(MyGatewareEventProcessor** freeMe) { delete *freeMe; *freeMe = nullptr; }