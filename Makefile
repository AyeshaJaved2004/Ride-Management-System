all: ./a.out

compRun:
	g++ -std=c++11 main.cpp Engine.cpp VehicleStatistics.cpp Vehicle.cpp Car.cpp Bike.cpp Truck.cpp Rickshaw.cpp Driver.cpp License.cpp CommercialLicense.cpp NonCommercialLicense.cpp TruckDriver.cpp CarDriver.cpp BikeDriver.cpp RickshawDriver.cpp DriverManager.cpp ManagerInfo.cpp customer.cpp fare.cpp feedback.cpp customer_manager.cpp location.cpp  -o r.out

compTest:
	g++ -std=c++11 test.cpp functions.cpp -o a.out

test: clean compTest; ./a.out

run: clean compRun; ./r.out

clean:
	rm -f *.out
