//
// Copyright (c) 2010-2016, Fabric Software Inc. All rights reserved.
//

#pragma once

#include <QtGui/QWidget>
#include <QtGui/QComboBox>
#include <QtCore/QEvent>

class FabricSpliceComboWidget : public QComboBox {
public:

  FabricSpliceComboWidget(QWidget * parent);

  virtual void clear();
  virtual bool event(QEvent * e);

  std::string getStdText();
  std::string getLastStdText() { return mLastText; }
  std::string itemStdText(unsigned int index);

  typedef void (*callback) (void * userData);
  void setCallback(callback func, void * userData);

private:
  callback mCallback;
  void * mCallbackUD;
  std::string mLastText;
};
