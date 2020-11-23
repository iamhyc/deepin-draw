/*
 * Copyright (C) 2019 ~ %YEAR% Deepin Technology Co., Ltd.
 *
 * Author:     WangXin
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef CSELECTTOOL_H
#define CSELECTTOOL_H
#include "idrawtool.h"
#include "globaldefine.h"
#include "csizehandlerect.h"


#include <QCursor>
#include <QTime>
#include <QPainterPath>

class CGraphicsItem;
class CGraphicsRotateAngleItem;
class CGraphicsItemGroup;
class CGraphicsItemHighLight;
class CGraphicsRectItem;
class GraphicsEllipseItem;
class QUndoCommand;

class CSelectTool : public IDrawTool
{
public:
    CSelectTool();

    ~CSelectTool() override;

    enum EOperateType { ENothingDo = 0,
                        ERectSelect,
                        EDragMove,
                        EResizeMove,
                        ERotateMove,
                        ECopyMove,
                        EDragSceneMove,
                        EOperateCount
                      };

    /**
     * @brief toolStart　工具开始事件
     * @param event      当次事件信息
     * @param pInfo      记录信息
     */
    void toolStart(CDrawToolEvent *event, ITERecordInfo *pInfo) override;

    /**
     * @brief toolStart　 工具刷新事件
     * @param event       当次事件信息
     * @param pInfo       记录信息
     */
    void toolUpdate(CDrawToolEvent *event, ITERecordInfo *pInfo) override;

    /**
     * @brief toolStart　工具结束事件
     * @param event      当次事件信息
     * @param pInfo      记录信息
     */
    void toolFinish(CDrawToolEvent *event, ITERecordInfo *pInfo) override;

    /**
     * @brief toolDoubleClikedEvent　双击事件
     * @param event      当次事件信息
     */
    void toolDoubleClikedEvent(IDrawTool::CDrawToolEvent *event, ITERecordInfo *pInfo) override;

    /**
     * @brief toolStart　判断工具活跃类型
     * @param event      当次事件信息
     * @param pInfo      记录信息
     */
    int decideUpdate(CDrawToolEvent *event, ITERecordInfo *pInfo) override;

    /**
     * @brief toolStart　鼠标hover事件（处理高亮，鼠标样式变化等）
     * @param event      当次事件信息
     */
    void mouseHoverEvent(IDrawTool::CDrawToolEvent *event) override;

    /**
     * @brief painter　绘制更多的内容（用于绘制框选矩形和高亮路径）
     * @param painter  绘制指针
     * @param rect     矩形大小
     * @param scene    场景指针
     */
    void drawMore(QPainter *painter, const QRectF &rect, CDrawScene *scene) override;

    /**
     * @brief copyItemsToScene　将items拷贝一份加入到scene中去（实现alt复制）
     * @param items             源items
     * @param scene             待加入到的场景
     */
    QList<QGraphicsItem *> copyItemsToScene(const QList<QGraphicsItem *> &items, CDrawScene *scene);

protected:
    bool returnToSelectTool(CDrawToolEvent *event, IDrawTool::ITERecordInfo *pInfo) override;

private:
    /* 当前有item正在被拖拽移动 */
    bool m_isItemMoving = false;

    /* 高亮路径 */
    QPainterPath _hightLight;
};

#endif // CSELECTTOOL_H
