#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <map>
#include <stack>
using namespace std;

constexpr int COMMAND_GROUP_NUM = 2;

enum class CommandName {
    LIGHT_ON = 0,
    LIGHT_OFF,
    TV_ON,
    TV_OFF,
};
/*
1. Light, TV类为具体的算法类
2. Command类为算法管理类的超类，因为算法多种多样，所以需要一个管理超类
3. LightOnControl 等类为具体的算法管理类
4. SimpleRemoteControl类为最后的执行类，可以储存不同的命令去执行，要更换或者增加命令，
只需要新增类命令管理类的子类即可



*/
class Light {
public:
    void LightOn() {
        cout << "LightOn" << endl;
    }

    void LightOff() {
        cout << "Light Off" << endl;
    }
};

class TV {
public:
    void TVOn() {
        cout << "TVOn" << endl;
    }

    void TVOff() {
        cout << "TV Off" << endl;
    }
};

class Command {
public:
    virtual void Excute() = 0;
    virtual void Undo() = 0;
};

class LightOnControl : public Command {
public:
    LightOnControl(Light light) {
        this->light = light;
    }

    void Excute() override {
        light.LightOn();
    }

    void Undo() override {
        light.LightOff();
    }

private:
    Light light;
};

class LightOffControl : public Command {
public:
    LightOffControl(Light light) {
        this->light = light;
    }

    void Excute() override {
        light.LightOff();
    }

    void Undo() override {
        light.LightOn();
    }

private:
    Light light;
};

class TVOnControl : public Command {
public:
    TVOnControl(TV tv) {
        this->tv = tv;
    }

    void Excute() override {
        tv.TVOn();
    }

    void Undo() override {
        tv.TVOff();
    }

private:
    TV tv;
};

class TVOffControl : public Command {
public:
    TVOffControl(TV tv) {
        this->tv = tv;
    }

    void Excute() override {
        tv.TVOff();
    }

    void Undo() override {
        tv.TVOn();
    }

private:
    TV tv;
};

class SimpleRemoteControl {
public:
    map<CommandName, shared_ptr<Command>> commandMap;
    stack<std::shared_ptr< Command>> excuteList;
    void SetCommand(CommandName commandName, shared_ptr<Command> command) {
        commandMap.insert(make_pair(commandName, command));
    }

    void ButtonWasPressed(CommandName commandName) {
        auto it = commandMap.find(commandName);
        if (it != commandMap.end()) {
            it->second->Excute();
            excuteList.push(it->second);
        }
    }

    void ButtonUndoWasPressed() {
        std::shared_ptr<Command> command = excuteList.top();
        command->Undo();
        excuteList.pop();
    }
};