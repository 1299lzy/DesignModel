// HeadFirst.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "FactoryModel.h"
#include "CommandModel.h"
#define TEST_FACTORY_MODEL
#define TEST_COMMAND_MODEL
int main()
{
    TEST_FACTORY_MODEL;
    ZunbaoPizza::GetInstance()->OrderPizza("fruit");
    KFCPizza::GetInstance()->OrderPizza("liuliang");
    ZunbaoPizza::GetInstance()->OrderPizza("liuliang");
    KFCPizza::GetInstance()->OrderPizza("fruit");

    TEST_COMMAND_MODEL;
    Light light;
    TV tv;
    LightOnControl lightOnControl(light);
    LightOffControl lightOffControl(light);
    TVOnControl tvOnControl(tv);
    TVOffControl tvOffControl(tv);
    SimpleRemoteControl control;
    control.SetCommand(CommandName::LIGHT_ON, make_shared<LightOnControl>(lightOnControl));
    control.SetCommand(CommandName::LIGHT_OFF, make_shared<LightOffControl>(lightOffControl));
    control.SetCommand(CommandName::TV_ON, make_shared<TVOnControl>(tvOnControl));
    control.SetCommand(CommandName::TV_OFF, make_shared<TVOffControl>(tvOffControl));
    control.ButtonWasPressed(CommandName::LIGHT_ON);
    control.ButtonUndoWasPressed();
    control.ButtonWasPressed(CommandName::LIGHT_OFF);
    control.ButtonWasPressed(CommandName::TV_ON);
    control.ButtonWasPressed(CommandName::TV_OFF);
    cout << "start undo........................." << endl;
    control.ButtonUndoWasPressed();
    control.ButtonUndoWasPressed();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
