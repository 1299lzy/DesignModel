#pragma once
#include <iostream>
#include <string>
#include <memory>

class Pizza {
public:
    virtual void Prepare() = 0;

    virtual void Bake() = 0;

    virtual void Cut() = 0;

    virtual void Box() = 0;
};

class ZunBaoLLPizza : public Pizza {
public:
    void Prepare() override {
        std::cout << "ZunBao LL Pizza Prepare" << std::endl;
    }

    void Bake() override {
        std::cout << "ZunBao LL Pizza Bake" << std::endl;
    }

    void Cut() override {
        std::cout << "ZunBao LL Pizza Cut" << std::endl;
    }

    void Box() override {
        std::cout << "ZunBao LL Pizza Box" << std::endl;
    }
};

class ZunBaoFruitPizza : public Pizza {
public:
    void Prepare() override {
        std::cout << "ZunBao Fruit Pizza Prepare" << std::endl;
    }

    void Bake() override {
        std::cout << "ZunBao Fruit Pizza Bake" << std::endl;
    }

    void Cut() override {
        std::cout << "ZunBao Fruit Pizza Cut" << std::endl;
    }

    void Box() override {
        std::cout << "ZunBao Fruit Pizza Box" << std::endl;
    }
};

class KFCLLPizza : public Pizza {
public:
    void Prepare() override {
        std::cout << "KFCLLPizza LL Pizza Prepare" << std::endl;
    }

    void Bake() override {
        std::cout << "KFCLLPizza LL Pizza Bake" << std::endl;
    }

    void Cut() override {
        std::cout << "KFCLLPizza LL Pizza Cut" << std::endl;
    }

    void Box() override {
        std::cout << "KFCLLPizza LL Pizza Box" << std::endl;
    }
};

class KFCFruitPizza : public Pizza {
public:
    void Prepare() override {
        std::cout << "KFCFruitPizza Fruit Pizza Prepare" << std::endl;
    }

    void Bake() override {
        std::cout << "KFCFruitPizza Fruit Pizza Bake" << std::endl;
    }

    void Cut() override {
        std::cout << "KFCFruitPizza Fruit Pizza Cut" << std::endl;
    }

    void Box() override {
        std::cout << "KFCFruitPizza Fruit Pizza Box" << std::endl;
    }
};

class PizzaStore {
public:
    virtual std::shared_ptr<Pizza> Create(std::string pizzaType) = 0;

    void OrderPizza(std::string type) {
        std::shared_ptr<Pizza> pizza = this->Create(type);
        pizza->Bake();
        pizza->Prepare();
        pizza->Cut();
        pizza->Box();
    }
};

class ZunbaoPizza : public PizzaStore {
public:
    std::shared_ptr<Pizza> Create(std::string pizzaType) override {
        if (pizzaType == "liuliang") {
            return std::make_shared<ZunBaoLLPizza>();
        }
        if (pizzaType == "fruit") {
            return std::make_shared<ZunBaoFruitPizza>();
        }
        return nullptr;
    }

    static std::unique_ptr<ZunbaoPizza> GetInstance() {
        static ZunbaoPizza zunbaoPizza;
        return std::make_unique<ZunbaoPizza>(zunbaoPizza);
    }
private:
    ZunbaoPizza() = default;
};

class KFCPizza : public PizzaStore {
public:
    std::shared_ptr<Pizza> Create(std::string pizzaType) override {
        if (pizzaType == "liuliang") {
            return std::make_shared<KFCLLPizza>();
        }
        if (pizzaType == "fruit") {
            return std::make_shared<KFCFruitPizza>();
        }
        return nullptr;
    }

    static std::unique_ptr<KFCPizza> GetInstance() {
        static KFCPizza kfcPizza;
        return std::make_unique<KFCPizza>(kfcPizza);
    }
private:
    KFCPizza() = default;
};