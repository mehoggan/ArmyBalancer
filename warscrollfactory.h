#ifndef WARSCROLLFACTORY_H
#define WARSCROLLFACTORY_H

#include <memory>

class WarScrollFactory
{
private:
  struct Private {};

public:
  explicit WarScrollFactory(const Private &);
  static WarScrollFactory& getSharedInstance();

private:
  WarScrollFactory &operator=(const WarScrollFactory &other) = delete;
  WarScrollFactory(const WarScrollFactory &other) = delete;
  WarScrollFactory(WarScrollFactory &&other) = delete;
};

#endif // WARSCROLLFACTORY_H
