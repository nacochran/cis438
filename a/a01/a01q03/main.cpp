#include <iostream>
#include <string>
#include <map>
#include <memory>

class Room
{
public:
    std::string name;
    std::map<std::string, std::shared_ptr<Room>> connections;

    Room(const std::string &name) : name(name) {}

    void connect(const std::string &direction, std::shared_ptr<Room> room)
    {
        connections[direction] = room;
    }

    std::shared_ptr<Room> getConnectedRoom(const std::string &direction)
    {
        if (connections.find(direction) != connections.end())
        {
            return connections[direction];
        }
        return nullptr;
    }
};

class Person
{
private:
    std::shared_ptr<Room> currentRoom;

public:
    void setLocation(std::shared_ptr<Room> room)
    {
        currentRoom = room;
    }

    std::shared_ptr<Room> getLocation()
    {
        return currentRoom;
    }

    void move(const std::string &direction)
    {
        auto nextRoom = currentRoom->getConnectedRoom(direction);
        if (nextRoom)
        {
            currentRoom = nextRoom;
            std::cout << "You moved to " << currentRoom->name << ".\n";
        }
        else
        {
            std::cout << "You can't go " << direction << " from here.\n";
        }
    }
};

void createDungeon(std::map<std::string, std::shared_ptr<Room>> &rooms)
{
    rooms["RoomA"] = std::make_shared<Room>("RoomA");
    rooms["RoomB"] = std::make_shared<Room>("RoomB");
    rooms["RoomC"] = std::make_shared<Room>("RoomC");

    rooms["RoomA"]->connect("North", rooms["RoomB"]);
    rooms["RoomB"]->connect("South", rooms["RoomA"]);

    rooms["RoomA"]->connect("East", rooms["RoomC"]);
    rooms["RoomC"]->connect("West", rooms["RoomA"]);
}

int main()
{
    std::map<std::string, std::shared_ptr<Room>> rooms;
    createDungeon(rooms);

    Person player;
    player.setLocation(rooms["RoomB"]);

    std::string command;
    std::cout << "Welcome to the Dungeon!\n";
    std::cout << "You are currently in " << player.getLocation()->name << ".\n";

    while (true)
    {
        std::cout << "Enter a direction (North, South, East, West) or 'quit' to exit: ";
        std::cin >> command;

        if (command == "quit")
        {
            std::cout << "Thanks for playing!\n";
            break;
        }

        player.move(command);
    }

    return 0;
}