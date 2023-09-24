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
1. Light, TV��Ϊ������㷨��
2. Command��Ϊ�㷨������ĳ��࣬��Ϊ�㷨���ֶ�����������Ҫһ��������
3. LightOnControl ����Ϊ������㷨������
4. SimpleRemoteControl��Ϊ����ִ���࣬���Դ��治ͬ������ȥִ�У�Ҫ���������������
ֻ��Ҫ�������������������༴��



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