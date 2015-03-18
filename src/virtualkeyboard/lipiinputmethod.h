/****************************************************************************
**
** Copyright (C) 2015 Digia Plc
** All rights reserved.
** For any questions to Digia, please use contact form at http://www.qt.io
**
** This file is part of the Qt Virtual Keyboard add-on for Qt Enterprise.
**
** Licensees holding valid Qt Enterprise licenses may use this file in
** accordance with the Qt Enterprise License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.
**
** If you have questions regarding the use of this file, please use
** contact form at http://www.qt.io
**
****************************************************************************/

#ifndef LIPIINPUTMETHOD_H
#define LIPIINPUTMETHOD_H

#ifdef HAVE_HUNSPELL
#include "hunspellinputmethod.h"
#define LipiInputMethodBase HunspellInputMethod
#else
#include "abstractinputmethod.h"
#define LipiInputMethodBase AbstractInputMethod
#endif

class LipiInputMethodPrivate;

class LipiInputMethod : public LipiInputMethodBase
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(LipiInputMethod)
public:
    explicit LipiInputMethod(QObject *parent = 0);
    ~LipiInputMethod();

    QList<DeclarativeInputEngine::InputMode> inputModes(const QString &locale);
    bool setInputMode(const QString &locale, DeclarativeInputEngine::InputMode inputMode);
    bool setTextCase(DeclarativeInputEngine::TextCase textCase);

    bool keyEvent(Qt::Key key, const QString &text, Qt::KeyboardModifiers modifiers);

    void reset();
    void update();

    void selectionListItemSelected(DeclarativeSelectionListModel::Type type, int index);

    QList<DeclarativeInputEngine::PatternRecognitionMode> patternRecognitionModes() const;
    DeclarativeTrace *traceBegin(DeclarativeInputEngine::PatternRecognitionMode patternRecognitionMode,
                                 const QVariantMap &traceCaptureDeviceInfo, const QVariantMap &traceScreenInfo);
    bool traceEnd(DeclarativeTrace *trace);

protected:
    void timerEvent(QTimerEvent *timerEvent);

protected slots:
    void resultsAvailable(const QVariantList &resultList);
};

#endif
