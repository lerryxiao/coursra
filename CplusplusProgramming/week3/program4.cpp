/**
   编程题＃4：魔兽世界之一：备战

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述

魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。

红司令部，City 1，City 2，……，City n，蓝司令部

两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值、攻击力这三种属性。

双方的武士编号都是从1开始计算。红方制造出来的第n个武士，编号就是n。同样，蓝方制造出来的第n个武士，编号也是n。

武士在刚降生的时候有一个生命值。

在每个整点，双方的司令部中各有一个武士降生。

红方司令部按照iceman、lion、wolf、ninja、dragon的顺序循环制造武士。

蓝方司令部按照lion、dragon、ninja、iceman、wolf的顺序循环制造武士。

制造武士需要生命元。

制造一个初始生命值为m的武士，司令部中的生命元就要减少m个。

如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。

给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。

一共有两种事件，其对应的输出样例如下：

1) 武士降生

输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter

表示在4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5，降生后蓝魔司令部里共有2个lion武士。（为简单起见，不考虑单词的复数形式）注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。

2) 司令部停止制造武士

输出样例： 010 red headquarter stops making warriors

表示在10点整，红方司令部停止制造武士

输出事件时：

首先按时间顺序输出；

同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

输入

第一行是一个整数，代表测试数据组数。

每组测试数据共两行。

第一行：一个整数M。其含义为， 每个司令部一开始都有M个生命元( 1 <= M <= 10000)。

第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000。

输出

对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。

对每组测试数据，首先输出"Case:n" n是测试数据的编号，从1开始 。

接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。

样例输入
1
20
3 4 5 6 7

样例输出
Case:1
000 red iceman 1 born with strength 5,1 iceman in red headquarter
000 blue lion 1 born with strength 6,1 lion in blue headquarter
001 red lion 2 born with strength 6,1 lion in red headquarter
001 blue dragon 2 born with strength 3,1 dragon in blue headquarter
002 red wolf 3 born with strength 7,1 wolf in red headquarter
002 blue ninja 3 born with strength 4,1 ninja in blue headquarter
003 red headquarter stops making warriors
003 blue iceman 4 born with strength 5,1 iceman in blue headquarter
004 blue headquarter stops making warriors

 */

#include <iostream>
#include <iomanip>

using namespace std;

class Warrior {
public:
    string name;
    int strength;
    int type;

    Warrior() {}

    Warrior(string n, int t, int s) {
        name = n;
        type = t;
        strength = s;
    }
};

class HeaderQuarter {
private:
    int strength;  //生命元
    int dragonCount, ninjiaCount, icemanCount, lionCount, wolfCount; //武士的数量
    int step;
    int order;
    int color;
public:
    Warrior dragon, ninja, iceman, lion, wolf;
    bool isStrength;
    string colorName;

    HeaderQuarter(int s);

    HeaderQuarter(const HeaderQuarter &h);

    int makeWarriors(int time);

    bool make(const Warrior *warrior, int time);

    void printfRecord(Warrior warrior, int count, int time);

    void setColor(int);
};


HeaderQuarter::HeaderQuarter(int s) {
    strength = s;
    dragonCount = 0;
    ninjiaCount = 0;
    icemanCount = 0;
    lionCount = 0;
    wolfCount = 0; //武士的数量
    step = 0;
    order = 1;
    isStrength = true;
}

HeaderQuarter::HeaderQuarter(const HeaderQuarter &h) {
    strength = h.strength;
    dragon = h.dragon;
    ninja = h.ninja;
    iceman = h.iceman;
    lion = h.lion;
    wolf = h.wolf;
    isStrength = true;
}

int HeaderQuarter::makeWarriors(int time) {
    //红方司令部按照iceman、lion、wolf、ninja、dragon的顺序循环制造武士。
    //蓝方司令部按照lion、dragon、ninja、iceman、wolf的顺序循环制造武士。
    if (strength < dragon.strength
        && strength < lion.strength
        && strength < ninja.strength
        && strength < iceman.strength
        && strength < dragon.strength)
    {
        isStrength = false;
        std::cout << std::setfill('0') << std::setw(3) << time << " ";
        std::cout << colorName << " headquarter stops making warriors" << std::endl;
        return 0;
    }
    switch (color) {
        case 1://red
            switch (step) {
                case 0:// iceman
                    if (!make(&iceman, time))
                    {
                        step++;
                        makeWarriors(time);
                    }
                    else
                    {
                        step++;
                    }
                    break;
                case 1://lion
                    if (!make(&lion, time))
                    {
                        step++;
                        makeWarriors(time);
                    }
                    else
                    {
                        step++;
                    }
                    break;
                case 2://wolf
                    if (!make(&wolf, time))
                    {
                        step++;
                        makeWarriors(time);
                    }
                    else
                    {
                        step++;
                    }
                    break;
                case 3://ninjia
                    if (!make(&ninja, time))
                    {
                        step++;
                        makeWarriors(time);
                    }
                    else
                    {
                        step++;
                    }
                    break;
                case 4://dragon
                    if (!make(&dragon, time))
                    {
                        step = 0;
                        makeWarriors(time);
                    }
                    else
                    {
                        step = 0;
                    }
                    break;
            }
            break;
        case 2://blue
            switch (step) {
                case 0:
                    if (!make(&lion, time))
                    {
                        step++;
                        makeWarriors(time);
                    }
                    else
                    {
                        step++;
                    }
                    break;
                case 1:
                    if (!make(&dragon, time))
                    {
                        step++;
                        makeWarriors(time);
                    }
                    else
                    {
                        step++;
                    }
                    break;
                case 2:
                    if (!make(&ninja, time))
                    {
                        step++;
                        makeWarriors(time);
                    }
                    else
                    {
                        step++;
                    }
                    break;
                case 3:
                    if (!make(&iceman, time))
                    {
                        step++;
                        makeWarriors(time);
                    }
                    else
                    {
                        step++;
                    }
                    break;
                case 4:
                    if (!make(&wolf, time))
                    {
                        step = 0;
                        makeWarriors(time);
                    }
                    else {
                        step = 0;
                    }
                    break;
            }

    }
    return 1;
}

bool HeaderQuarter::make(const Warrior *warrior,int time) {
    if (strength >= warrior->strength) {
        strength = strength - warrior->strength;
        //dragon >> ninja >> iceman >> lion >> wolf;
        switch (warrior->type) {
            case 1: // dragon
                dragonCount++;
                printfRecord(dragon, dragonCount, time);
                break;
            case 2:
                ninjiaCount++;
                printfRecord(ninja, ninjiaCount, time);
                break;
            case 3:
                icemanCount++;
                printfRecord(iceman, icemanCount, time);
                break;
            case 4:
                lionCount++;
                printfRecord(lion, lionCount, time);
                break;
            case 5:
                wolfCount++;
                printfRecord(wolf, wolfCount, time);
                break;
        }
        order++;
        return true;
    }
    return false;
}

void HeaderQuarter::printfRecord(Warrior warrior, int count, int time) {
    std::cout << std::setfill('0') << std::setw(3) << time;
    std::cout << " "
              << colorName << " "
              << warrior.name << " "
              << order << " born with strength "
              << warrior.strength << ","
              << count << " " << warrior.name
              << " in " << colorName << " headquarter" << endl;
}

void HeaderQuarter::setColor(int color) {
    this->color = color;
    switch (color) {
        case 1:
            colorName = "red";
            break;
        case 2:
            colorName = "blue";
            break;
    }
}

int main() {
    int n;
    int m;
    bool isStrength;
    int dragon, ninja, iceman, lion, wolf;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        HeaderQuarter red(m);
        red.setColor(1);
        std::cin >> dragon >> ninja >> iceman >> lion >> wolf;
        red.dragon = Warrior("dragon", 1, dragon);
        red.ninja = Warrior("ninja", 2, ninja);
        red.iceman = Warrior("iceman", 3, iceman);
        red.lion = Warrior("lion", 4, lion);
        red.wolf = Warrior("wolf", 5, wolf);
        HeaderQuarter blue(red);
        blue.setColor(2);
        cout << red.colorName << "    " << blue.colorName << endl;
        // make worriors
        isStrength = true;

        //同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。
        std::cout << "Case:" << i + 1 << std::endl;
        int hour = 0;
        while (isStrength) {
            if (red.isStrength) {
                red.makeWarriors(hour);
            }
            if (blue.isStrength) {
                blue.makeWarriors(hour);
            }
            if (!red.isStrength && !blue.isStrength) {
                isStrength = false;
            }
            hour++;
            hour = hour % 24;
        }
    }
    return 0;
}

