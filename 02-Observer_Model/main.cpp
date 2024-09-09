#include <iostream>
#include <string>
#include <memory>
#include <list>
#include <unistd.h>

using namespace std;

class NewspaperSubject;

class IObserver {
public:
    virtual ~IObserver() {};
    virtual void attach(NewspaperSubject* subject) = 0;
    virtual void detach(NewspaperSubject* subject) = 0;
    virtual void update(const string& notify_msg) = 0;
};

class NewspaperSubject {
public:
    virtual ~NewspaperSubject() {};
    virtual void attach(IObserver *) = 0;
    virtual void detach(IObserver *) = 0;
    virtual void notify() = 0;
};

class BaseSubject : public NewspaperSubject {
public:
    BaseSubject(string subject_name):subject_name_(subject_name) {}
    void attach(IObserver *) override;
    void detach(IObserver *) override;
    void notify() override;
    void createMessage(const string& msg);

private:
    list<IObserver *> observers_;
    string message_info_;
    string subject_name_;
};

void BaseSubject::attach(IObserver *observer)
{
    observers_.push_back(observer);
}

void BaseSubject::detach(IObserver *observer)
{
    observers_.remove(observer);
}

void BaseSubject::createMessage(const string& msg)
{
    message_info_ = msg;
    cout << subject_name_ << " publish : " << message_info_ << endl;
    notify();
}

void BaseSubject::notify()
{
    if (observers_.empty()) {
        return ;
    }
    for (auto observer : observers_) {
        observer->update(message_info_);
    }

}

class Display {
public:
    virtual ~Display() {};
    virtual void display() = 0;
};

class StudentObserver : public IObserver, Display {
public:
    StudentObserver(string observer_name);
    void attach(NewspaperSubject* subject) override;
    void detach(NewspaperSubject* subject) override;
    void update(const string& notify_msg) override;
    void display() override;

private:
    string message_from_subject_;
    string observer_name_;
};

StudentObserver::StudentObserver(string observer_name)
{
    observer_name_ = observer_name;
}

void StudentObserver::attach(NewspaperSubject* subject)
{
    subject->attach(this);
}

void StudentObserver::detach(NewspaperSubject* subject)
{
    subject->detach(this);
}

void StudentObserver::update(const string& notify_msg)
{
    message_from_subject_ = notify_msg;
    display();
}

void StudentObserver::display()
{
    cout << observer_name_ << " get: " << message_from_subject_ << endl;
}

int main()
{
    BaseSubject *subject_a = new BaseSubject("新浪报纸");
    BaseSubject *subject_b = new BaseSubject("腾讯游戏日报");
    BaseSubject *subject_c = new BaseSubject("军事简报");
    IObserver *observer_a= new StudentObserver("李老师");
    IObserver *observer_b = new StudentObserver("杨同学");

    observer_a->attach(subject_a);
    observer_a->attach(subject_b);
    observer_a->attach(subject_c);
    observer_b->attach(subject_b);


    subject_a->createMessage("2014-09-07 每日新闻");
    subject_b->createMessage("2014-09-07 腾讯游戏日报");
    subject_c->createMessage("2014-09-07 军事简报");

    return 0;
}