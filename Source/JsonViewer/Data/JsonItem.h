/****************************************************************************
**
** Copyright (C) 2010-2012 B.D. Mihai.
**
** This file is part of JSON Viewer.
**
** JSON Viewer is free software: you can redistribute it and/or modify it 
** under the terms of the GNU Lesser Public License as published by the Free 
** Software Foundation, either version 3 of the License, or (at your option) 
** any later version.
**
** JSON Viewer is distributed in the hope that it will be useful, but 
** WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
** or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser Public License for 
** more details.
**
** You should have received a copy of the GNU Lesser Public License along 
** with JSON Viewer.  If not, see http://www.gnu.org/licenses/.
**
****************************************************************************/

#ifndef JSONITEM_H
#define JSONITEM_H

/*!
This class represents a JSON item. Depending on the type can have a value or
additional sub items.
*/
class JsonItem : public QList<JsonItem*>
{


  public:
    enum ItemType
    {
      ValueType,
      ArrayType,
      ComplexType
    };

  public:
    JsonItem(JsonItem *itemParent);
    virtual ~JsonItem();

    QString   name()   { return itemName;   }
    QVariant  value()  { return itemValue;  }
    JsonItem *parent() { return itemParent; }
    ItemType  type()   { return itemType;   }

    void setName(const QString &itemName) { this->itemName = itemName; }
    void setValue(const QVariant &itemValue) { this->itemValue = itemValue; }
    void setType(const ItemType &itemType) { this->itemType = itemType; }

  protected:
    JsonItem *itemParent;
    QString   itemName;
    QVariant  itemValue;
    ItemType  itemType;
};

#endif // JSONITEM_H
